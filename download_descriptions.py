import argparse
import os
import pathlib
import re
import time
from typing import List

import bs4
import requests
import selenium.webdriver


def get_chrome_driver() -> selenium.webdriver.Chrome:
    chrome_opts = selenium.webdriver.ChromeOptions()
    chrome_opts.headless = True
    driver = selenium.webdriver.Chrome(options=chrome_opts)
    return driver


def get_source(
    url: str,
    driver: selenium.webdriver.Chrome = None,
    page_load_wait: float = 1
) -> bs4.BeautifulSoup:
    """
    """
    if driver is None:
        driver = get_chrome_driver()

    driver.get(url)
    time.sleep(page_load_wait)
    return bs4.BeautifulSoup(driver.page_source, "html.parser")


def parse_description(source: bs4.BeautifulSoup):
    description = source.find("div", {"data-key": "description-content"})

    title_ = description.find("div", {"data-cy": "question-title"})
    title = title_.text

    content = description.find(
        "div", {"class": re.compile(r".*question-content.*")}
    )
    content = list(content.children)[0]

    lines, image_urls = convert_to_markdown(title, content)
    return lines, image_urls


def convert_to_markdown(title: str, content: bs4.element.Tag):
    lines = [f"# {title}"]
    image_urls = dict()

    replacements =  {
        #"<code>": r"`",
        #"</code>": r"`",
        "<em>": "*",
        "</em>": "*",
        "<li>": "",
        "</li>": "",
        "<p>": "",
        "</p>": "",
        "<strong>": "**",
        "</strong>": "**",
        "&gt;": ">",
        "&lt;": "<",
        "\xa0": "\n",
    }
    
    def replace(s: str):
        for k, v in replacements.items():
            s = s.replace(k, v)
        return s

    for elem in content.children:
        if elem.name == "p":
            text = replace(str(elem))
            lines.append(text + "\n")
        elif elem.name == "img":
            image_url = elem["src"]

            image_expr = r"\d{4}/\d{2}/\d{2}/.+$"
            match = re.search(image_expr, image_url)
            image_fname = match.group().replace("/", "_")
            image_fpath = f"/img/{image_fname}"

            image_urls[image_url] = image_fname

            lines.append(f"![]({image_fpath})")
        elif elem.name == "pre":
            lines.append("```")
            lines.extend(elem.text.split("\n"))
            lines.append("```")
        elif elem.name == "ul":
            for li in elem.findAll("li"):
                bullet_text = replace(str(li))
                lines.append(f"* {bullet_text}")

    return lines, image_urls


def write_markdown(lines: List[str], fpath: pathlib.Path):
    with open(fpath, "w") as f:
        for line in lines:
            f.write(line + "\n")


def download_image(image_url: str, dst_fpath: pathlib.Path):
    response = requests.get(image_url)
    if response.status_code == 200:
        img = response.content

        if not dst_fpath.exists():
            with open(dst_fpath, "wb") as f:
                f.write(img)
    else:
        raise RuntimeError(f"Error downloading image {image_url}")


def download_images(image_urls: List[str], dst_dir: pathlib.Path):
    for image_url, local_fname in image_urls.items():
        local_fpath = dst_dir / local_fname
        download_image(image_url, local_fpath)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--all", action="store_true",
        help="Automatically download and add descriptions for all directories "
        "without README.md files in them"
    )

    parser.add_argument("--dst-dir", type=pathlib.Path)
    parser.add_argument("--img-dir", type=pathlib.Path, default="img")
    parser.add_argument("--url", "-u", type=str)

    args = parser.parse_args()

    if not args.img_dir.exists():
        args.img_dir.mkdir()

    urls = []
    dst_fpaths = []

    if args.all:
        for path in pathlib.Path("leetcode").iterdir():
            title = path.name.split("_")
            title = "-".join(title[1:])

            url = f"https://leetcode.com/problems/{title}"
            dst_fpath = path / "README.md"

            if not dst_fpath.exists():
                urls.append(url)
                dst_fpaths.append(dst_fpath)
    else:
        urls.append(args.url)
        dst_fpaths.append(args.dst_dir / "README.md")

    for url, dst_fpath in zip(urls, dst_fpaths):
        print(f"Downloading {url}")
        source = get_source(url)
        lines, image_urls = parse_description(source)
        lines.insert(0, url)
        write_markdown(lines, dst_fpath)
        download_images(image_urls, args.img_dir)
