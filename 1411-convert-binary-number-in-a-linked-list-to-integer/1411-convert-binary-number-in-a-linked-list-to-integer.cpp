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
    int getDecimalValue(ListNode* head) {
        ListNode* start = head;
        int n = 0;
        while(start != NULL){
            n++;
            start = start->next;
        }
        start = head;
        n = n-1;
        int ans = 0;
        while(start != NULL){
            ans += start->val * pow(2,n);
            n--;
            start = start->next;
        }
        return ans;
    }
};