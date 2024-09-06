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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        set<int> invalidNum(nums.begin(),nums.end());
        ListNode* newHead = head;
        while(newHead){
            if(invalidNum.find(newHead->val) == invalidNum.end()){
                break;
            }
            newHead = newHead->next;
        }
        ListNode* finalHead = newHead;
        while(newHead && newHead->next){
            if(invalidNum.find(newHead->next->val) == invalidNum.end()){
                newHead = newHead->next;
            }
            else{
                newHead->next = newHead->next->next;
            }
        }
        return finalHead;
    }
};