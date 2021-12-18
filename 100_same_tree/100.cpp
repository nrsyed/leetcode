/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> p_queue;
        std::queue<TreeNode*> q_queue;
        p_queue.push(p);
        q_queue.push(q);
        
        while (!p_queue.empty() && !q_queue.empty()) {
            TreeNode* p = p_queue.front();
            p_queue.pop();
            
            TreeNode* q = q_queue.front();
            q_queue.pop();
            
            if (
                (p == nullptr && q != nullptr)
                || (p != nullptr && q == nullptr)
            ) {
                return false;
            } else if (p != nullptr) {
                if (p->val != q->val) {
                    return false;
                }
                p_queue.push(p->left);
                p_queue.push(p->right);
                q_queue.push(q->left);
                q_queue.push(q->right);
            }
        }
        return true;
    }
};
