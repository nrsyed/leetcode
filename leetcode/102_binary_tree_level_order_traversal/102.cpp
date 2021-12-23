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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        
        if (root == nullptr) {
            return ret;
        }
        
        ret.emplace_back(vector<int>());
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        int level {0};
        while (!q.empty()) {
            int nodes_added {0};
            while (!q.empty() && (q.front() != nullptr)) {
                TreeNode* node {q.front()};
                q.pop();
                
                ret[level].push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                    nodes_added++;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    nodes_added++;
                }
            }
            q.pop();
            if (nodes_added) {
                q.push(nullptr);
                ret.emplace_back(vector<int>());
                level++;
            }
        }
        
        return ret;
    }
};
