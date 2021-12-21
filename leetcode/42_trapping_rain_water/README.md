https://leetcode.com/problems/trapping-rain-water
# 42. Trapping Rain Water
Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.




**Example 1:**

![](/img/2018_10_22_rainwatertrap.png)
```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```
**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9

```



**Constraints:**

* <code>n == height.length</code>
* <code>1 <= n <= 2 * 10<sup>4</sup></code>
* <code>0 <= height[i] <= 10<sup>5</sup></code>
