# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        p_queue = [p]
        q_queue = [q]
        
        while p_queue and q_queue:
            p = p_queue.pop(0)
            q = q_queue.pop(0)
            
            if bool(p) != bool(q):
                return False
            elif p is not None:
                if p.val != q.val:
                    return False
                
                p_queue.append(p.left)
                p_queue.append(p.right)
                q_queue.append(q.left)
                q_queue.append(q.right)
        return True
