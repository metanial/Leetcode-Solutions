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
        ListNode* result = new ListNode(0);
        ListNode* tail = result;
        int carry = 0;
        while(l1 && l2) {
            tail->next = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;
            tail = tail->next;
        }
        while(l1) {
            tail->next = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry)/10;
            l1 = l1->next;
            tail = tail->next;
        }
        while(l2) {
            tail->next = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry)/10;
            l2 = l2->next;
            tail = tail->next;
        }
        if(carry > 0) tail->next = new ListNode(carry);
        return result->next;
    }
};