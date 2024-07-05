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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        vector<int> idx;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* ahead = curr->next;
        int i = 2;

        while(ahead != NULL){
            if(curr->val < prev->val && curr->val < ahead->val){
                idx.push_back(i);
            }
            if(curr->val > prev->val && curr->val > ahead->val){
                idx.push_back(i);
            }
            i++;
            prev = curr;
            curr = curr->next;
            ahead = curr->next;
        }
        int minDist = -1, maxDist = -1;
        if(idx.size() > 1){
            sort(idx.begin(),idx.end());
            minDist = INT_MAX, maxDist = idx[idx.size()-1] - idx[0];
            for(int j=idx.size()-1; j>0; j--){
                minDist = min(minDist,idx[j]-idx[j-1]);
            }
        }
        ans.push_back(minDist);
        ans.push_back(maxDist);
        return ans;
    }
};