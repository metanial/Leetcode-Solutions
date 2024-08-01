/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            if(fast->next->next != NULL) fast = fast->next->next;
            else return 0;

            slow = slow->next;
            if(fast == slow) return 1;
        }

        return 0;
    }
};