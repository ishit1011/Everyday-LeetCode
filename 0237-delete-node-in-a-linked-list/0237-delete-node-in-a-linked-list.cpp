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
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* prev = NULL;
        int storeVal = 0;
        while(temp->next != NULL){
            storeVal = temp->val;
            temp->val = temp->next->val;
            temp->next->val = storeVal;
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete(temp);
    }
};