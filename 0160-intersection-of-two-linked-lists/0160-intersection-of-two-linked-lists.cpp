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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        int a = 1, b = 1;
        while(curr1 != NULL){
            a++;
            curr1 = curr1->next;
        }
        while(curr2 != NULL){
            b++;
            curr2 = curr2->next;
        }
        int diff = abs(a-b);
        curr1 = headA;
        curr2 = headB;
        if(a > b){
            while(diff--){
                curr1 = curr1->next;
            }
        }
        if(a < b){
            while(diff--){
                curr2 = curr2->next;
            }
        }
        while(curr1 != NULL || curr2 != NULL){
            if(curr1 == curr2){
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;
    }
};