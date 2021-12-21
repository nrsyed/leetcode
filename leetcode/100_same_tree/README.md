https://leetcode.com/problems/same-tree
# 100. Same Tree
Given the roots of two binary trees <code>p</code> and <code>q</code>, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.




**Example 1:**

![](/img/2020_12_20_ex1.jpg)
```
Input: p = [1,2,3], q = [1,2,3]
Output: true

```
**Example 2:**

![](/img/2020_12_20_ex2.jpg)
```
Input: p = [1,2], q = [1,null,2]
Output: false

```
**Example 3:**

![](/img/2020_12_20_ex3.jpg)
```
Input: p = [1,2,1], q = [1,1,2]
Output: false

```



**Constraints:**

* The number of nodes in both trees is in the range <code>[0, 100]</code>.
* <code>-10<sup>4</sup> <= Node.val <= 10<sup>4</sup></code>
