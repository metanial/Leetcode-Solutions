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
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int rem = 0;
        while(l1 && l2) {
            temp->next = new ListNode((l1->val + l2->val + rem)%10);
            rem = (l1->val + l2->val + rem)/10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while(l1) {
            temp->next = new ListNode((l1->val + rem)%10);
            rem = (l1->val + rem)/10;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2) {
            temp->next = new ListNode((l2->val + rem)%10);
            rem = (l2->val + rem)/10;
            l2 = l2->next;
            temp = temp->next;
        }
        if(rem > 0) temp->next = new ListNode(rem);
        return ans->next;
    }
};