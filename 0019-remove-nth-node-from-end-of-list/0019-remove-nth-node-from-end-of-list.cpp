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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n==1){
            return NULL;
        }
        ListNode* s1 = head;
        ListNode* s2 = head;
        ListNode* prev = NULL;
        int diff = n-1;
        while(diff--){
            s2 = s2->next;
        }
        while(s2->next != NULL){
            prev = s1;
            s1 = s1->next;
            s2 = s2->next;
        }
        if(prev == NULL){
            head = s1->next;
        }
        else{
            prev->next = s1->next;
        }
        return head;
    }
};