class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_substr = 0
        max_num_chars = len(set(s))
        for i in range(len(s)):
            seen = {s[i]}
            j = i + 1
            while j < len(s) and s[j] not in seen:
                seen.add(s[j])
                j += 1
            if len(seen) > longest_substr:
                longest_substr = len(seen)
            if longest_substr == max_num_chars:
                break
        return longest_substr
