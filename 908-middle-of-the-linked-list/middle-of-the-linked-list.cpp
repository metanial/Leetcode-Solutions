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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        ListNode* mid = head;
        
        while(curr->next != NULL && curr->next->next != NULL) {
            curr = curr->next->next;
            mid = mid->next;
        }
        if(curr->next != NULL) mid = mid->next;
        return mid;
    }
};