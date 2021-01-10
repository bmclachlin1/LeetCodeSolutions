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
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        
        ListNode* curr = head;
        while (curr != NULL) {
            list.push_back(curr->val);
            curr = curr->next;
        }
        
        for (int i = 0; i < list.size() / 2; i++) {
            int j = list.size() - i - 1;
            if (list[i] != list[j]) {
                return false;
            }
        }
        
        return true;
    }
};