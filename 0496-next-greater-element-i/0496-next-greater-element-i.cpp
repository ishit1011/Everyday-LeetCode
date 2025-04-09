class Solution {
public:
    int findEle(vector<int>& nums2, int val){
        for(int i=0; i<nums2.size(); i++){
            if(val == nums2[i]){
                return i;
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> greaterEle;
        stack<int> stk;
        for(int i=n2-1; i>=0; i--){
            if(stk.empty()){
                greaterEle.push_back(-1);
            }
            else{
                while(!stk.empty() && stk.top() < nums2[i]){
                    stk.pop();
                }
                if(stk.empty()){
                    greaterEle.push_back(-1);
                }
                else{
                    greaterEle.push_back(stk.top());
                }
            }
            stk.push(nums2[i]);
        }
        reverse(greaterEle.begin(),greaterEle.end());
        cout<<"Greater Ele : ";
        for(int i=0; i<n2; i++){
            cout<<greaterEle[i]<<" ";
        }
        vector<int> ans;
        for(int i=0; i<n1; i++){
            int idx = findEle(nums2,nums1[i]);
            if(idx != -1){
                ans.push_back(greaterEle[idx]);
            }
        }
        return ans;
    }
};