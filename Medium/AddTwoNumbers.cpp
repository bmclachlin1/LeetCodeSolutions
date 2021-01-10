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
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        // continue while at least one list node is valid
        while (l1 != nullptr || l2 != nullptr) {
            // if l1 is null then we add 0, else we add l1's val
            int x = (l1 == nullptr) ? 0 : l1->val; 
            // if l2 is null then we add 0, else we add l2's val
            int y = (l2 == nullptr) ? 0 : l2->val;
            // update the current sum, this can be > 10
            int sum = x + y + carry;
            // update carry
            carry = sum / 10;
            // create a new node of sum modulo 10, so that digit is in range (0-9)
            curr->next = new ListNode(sum % 10);
            // advance curr to next position in linked list
            curr = curr->next;
            // advance l1 and l2 if valid
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry == 1) {
            curr->next = new ListNode(1);
        }
        return dummyHead->next;
    }
};