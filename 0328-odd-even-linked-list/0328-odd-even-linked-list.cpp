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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next ||  head->next->next == NULL) return head;
        ListNode* oddPtr = head;
        ListNode* evenPtr = head->next;
        ListNode* evenHead = evenPtr;
        while(oddPtr->next != NULL && evenPtr->next != NULL){
            oddPtr->next = evenPtr->next;
            oddPtr = oddPtr->next;
            evenPtr->next = evenPtr->next->next;
            evenPtr = evenPtr->next;
        }
        oddPtr->next = evenHead;
        return head;
    }
};