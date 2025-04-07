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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        k = k % cnt;
        ListNode* last = head;
        ListNode* secondLast = NULL;
        ListNode* first = head;
        while(k--){
            while(last->next != NULL){
                secondLast = last;
                last = last->next;
            }
            if(secondLast && last && first){
                secondLast->next = NULL;
            last->next = first;
            first = last;
            }
        }
        return first;
    }
};