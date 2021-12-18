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
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            
            if (!(node == nullptr)) {
                TreeNode* tmp {node->right};
                node->right = node->left;
                node->left = tmp;
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        return root;
    }
};
