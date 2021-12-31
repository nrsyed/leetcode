https://leetcode.com/problems/longest-increasing-subsequence
# 300. Longest Increasing Subsequence
Given an integer array <code>nums</code>, return the length of the longest strictly increasing subsequence.

A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, <code>[3,6,2,7]</code> is a subsequence of the array <code>[0,3,1,6,2,2,7]</code>.




**Example 1:**

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

```
**Example 2:**

```
Input: nums = [0,1,0,3,2,3]
Output: 4

```
**Example 3:**

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1

```



**Constraints:**

* <code>1 <= nums.length <= 2500</code>
* <code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code>



<b>Follow up:</b>
Can you come up with an algorithm that runs in
<code>O(n log(n))</code> time complexity?

