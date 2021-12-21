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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        
        ListNode* node {head};
        while (node) {
            node = node->next;
            len++;
        }
        
        int idx_to_remove = len - n;
        
        if (idx_to_remove == 0) {
            return head->next;
        }
        
        node = head;
        ListNode** p_next;
        
        for (int i = 0; i < idx_to_remove; ++i) {
            p_next = &(node->next);
            node = node->next;
        }
        *p_next = node->next;
        
        return head;
    }
};
