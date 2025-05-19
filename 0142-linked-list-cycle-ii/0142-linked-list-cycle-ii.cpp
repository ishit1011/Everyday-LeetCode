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
    ListNode* hasCycle(ListNode *head) {
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
        return meetCnt == 2 ? slow : NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* kNode = hasCycle(head);
        if(!kNode) return NULL;
        ListNode* start = head;
        cout<<"kNode : "<<kNode->val;
        while(!(start == kNode)){
            start = start->next;
            kNode = kNode->next;
        }
        return kNode;
    }
};