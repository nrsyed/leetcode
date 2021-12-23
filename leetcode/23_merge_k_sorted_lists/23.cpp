/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Comparator {
public:
    Comparator() {}
    
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;
        
        for (ListNode* head : lists) {
            ListNode* node {head};
            while (node) {
                pq.push(node);
                node = node->next;
            }
        }
        
        ListNode* head {nullptr};
        ListNode** prev_next;
        
        int i = 0;
        while (!pq.empty()) {
            ListNode* node {pq.top()};
            pq.pop();
            
            node->next = nullptr;
            if (i == 0) {
                head = node;
            } else {
                *prev_next = node;
            }
            prev_next = &(node->next);
            i++;
        }
        return head;
    }
};
