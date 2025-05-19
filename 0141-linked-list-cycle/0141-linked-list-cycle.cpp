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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int meetCnt = 0;
        while(fast != NULL && fast->next != NULL){
            if(slow == fast){
                meetCnt++;
                if(meetCnt >= 2) break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return meetCnt == 2;
    }
};