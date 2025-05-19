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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            n++;
        }
        if(n == 1) return NULL;
        temp = head;
        int mid = n/2;
        mid -= 1;
        while(mid-- && temp->next != NULL){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};