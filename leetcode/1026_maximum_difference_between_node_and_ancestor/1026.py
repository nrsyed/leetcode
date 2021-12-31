# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: TreeNode) -> Tuple[int, int, int]:
        """
        Returns: min value of the subtree, max value of the subtree, and max
            diff of the subtree at ``node``.
        """
        child_min = node.val
        child_max = node.val
        max_child_diff = 0
        
        for child in (node.left, node.right):
            if child:
                child_min_, child_max_, child_diff = self.dfs(child)
                child_min = child_min_ if child_min_ < child_min else child_min
                child_max = child_max_ if child_max_ > child_max else child_max
                max_child_diff = child_diff if child_diff > max_child_diff else max_child_diff
            
        max_diff = max(
            abs(node.val - child_min),
            abs(node.val - child_max),
            max_child_diff
        )
        min_ = child_min if child_min < node.val else node.val
        max_ = child_max if child_max > node.val else node.val
        
        return min_, max_, max_diff
        
    
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        _, _, max_diff = self.dfs(root)
        return max_diff
