https://leetcode.com/problems/maximum-difference-between-node-and-ancestor
# 1026. Maximum Difference Between Node and Ancestor
Given the <code>root</code> of a binary tree, find the maximum value <code>v</code> for which there exist **different** nodes <code>a</code> and <code>b</code> where <code>v = |a.val - b.val|</code> and <code>a</code> is an ancestor of <code>b</code>.

A node <code>a</code> is an ancestor of <code>b</code> if either: any child of <code>a</code> is equal to <code>b</code>
or any child of <code>a</code> is an ancestor of <code>b</code>.




**Example 1:**

![](/img/2020_11_09_tmp-tree.jpg)
```
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```
**Example 2:**

![](/img/2020_11_09_tmp-tree-1.jpg)
```
Input: root = [1,null,2,null,0,3]
Output: 3

```



**Constraints:**

* The number of nodes in the tree is in the range <code>[2, 5000]</code>.
* <code>0 <= Node.val <= 10<sup>5</sup></code>
