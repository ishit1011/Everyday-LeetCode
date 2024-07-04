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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head->next;

        while(curr != NULL){
            while(curr->val != 0){
                curr = curr->next;
                prev->val += curr->val;
            }
            prev->next = curr->next;
            curr = curr->next;
            prev = curr;
        }
        return head->next;
    }
};