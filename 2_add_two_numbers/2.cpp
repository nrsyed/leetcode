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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 {l1};
        ListNode* node2 {l2};
        
        ListNode* head {nullptr};
        ListNode** ptr_to_prev_next;
        bool carry_one = false;
        
        while (node1 != nullptr || node2 != nullptr || carry_one) {
            int curr_sum = 0;
            
            if (node1 != nullptr) {
                curr_sum += node1->val;
                node1 = node1->next;
            }
            if (node2 != nullptr) {
                curr_sum += node2->val;
                node2 = node2->next;
            }
            
            if (carry_one) {
                curr_sum++;
                carry_one = false;
            }
            
            int digit {curr_sum % 10};
            
            if (curr_sum / 10 == 1) {
                carry_one = true;
            }
            
            ListNode* node = new ListNode;
            node->val = digit;
            
            if (head == nullptr) {
                head = node;
            } else {
                *ptr_to_prev_next = node;
            }
            
            ptr_to_prev_next = &(node->next);
            
        }
        return head;
    }
};
