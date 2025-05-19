class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1] <= nums[2]) return "none";
        set<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        string ans;
        int m = st.size();
        if(m == 3) ans = "scalene";
        if(m == 2) ans = "isosceles";
        if(m == 1) ans = "equilateral";
        
        return ans;
    }
};