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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* last = &dummy;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                // point to next
                last->next = l1;
                // advance last forwards in l1
                last = l1;
                // advance l1 forwards in l1
                l1 = l1->next;
            } 
            // l1-val > l2->val or l1-val == l2->val
            else {
                // point to next
                last->next = l2;
                // advance last forwards in l2
                last = l2;
                // advance l2 forwards in l2
                l2 = l2->next;
            }
        }
        
        // either l1 == NULL or l2 == NULL, so check for each case
        // don't have to loop through whole list because pointing last to 
        // l1 or l2, then l1 and l2 already sorted
        if (l1 != NULL) {
            last->next = l1;
        } else if (l2 != NULL) {
            last->next = l2;
        }
        
        return dummy.next;
    }
};