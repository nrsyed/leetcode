/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

void dfs(Node* node, unordered_map<int, Node*>& copy_map) {
    if (!copy_map.count(node->val)) {
        Node* copy = new Node(node->val);
        copy_map[node->val] = copy;
    }
    
    for (Node* neighbor : node->neighbors) {
        if (!copy_map.count(neighbor->val)) {
            dfs(neighbor, copy_map);
        }
        copy_map[node->val]->neighbors.push_back(copy_map[neighbor->val]);
    }
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        
        unordered_map<int, Node*> copy_map;
        dfs(node, copy_map);
        return copy_map[1];
    }
};
