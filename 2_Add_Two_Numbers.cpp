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
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* current = head;
        while (l1 != nullptr && l2 != nullptr) {
            int new_val = l1->val + l2->val + carry;
            // to calculate the carry
            carry = new_val / 10;
            new_val = new_val % 10;

            // set the pointer
            current->next = new ListNode(new_val);
            current = current->next; // next pointer

            // get the next pointers
            l1 = l1->next; 
            l2 = l2->next;
        }
        // are there still values in l1?
        while(l1 != nullptr) {
            int new_val = l1->val + carry;
            // to calculate the carry
            carry = new_val / 10;
            new_val = new_val % 10;

            // set the pointer
            current->next = new ListNode(new_val);
            current = current->next; // next pointer

            l1 = l1->next; 
        }
        // are there still values in l2?
        while(l2 != nullptr) {
            int new_val = l2->val + carry;
            // to calculate the carry
            carry = new_val / 10;
            new_val = new_val % 10;

            // set the pointer
            current->next = new ListNode(new_val);
            current = current->next; // next pointer

            l2 = l2->next;
        }
        if (carry != 0){
            current->next = new ListNode(carry);
            current = current->next; // next pointer
        }
        return head->next;
    }
};
