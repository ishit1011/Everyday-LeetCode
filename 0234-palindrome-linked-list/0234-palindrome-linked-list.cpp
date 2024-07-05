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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return (head);
        }
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode* ahead = new ListNode(curr->val);
            ahead->next = prev;
            prev = ahead;
            curr = curr->next;
        }
        ListNode* revHead = prev;
        cout<<head->next->val<<endl;
        ListNode* currHead = head;

        while(currHead && revHead){
            if(currHead->val != revHead->val){
                return false;
            }
            currHead = currHead->next;
            revHead = revHead->next;
            
        }
        return true;
    }
};