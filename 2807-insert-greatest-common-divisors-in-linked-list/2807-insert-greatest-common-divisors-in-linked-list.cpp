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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head; 
        ListNode* tempNxt = temp->next;
        while(tempNxt){
            int gcdVal = gcd(temp->val,tempNxt->val);
            ListNode* curr = new ListNode(gcdVal);
            temp->next = curr;
            curr->next = tempNxt;
            temp = tempNxt;
            tempNxt = temp->next;
        }
        return head;
    }
};