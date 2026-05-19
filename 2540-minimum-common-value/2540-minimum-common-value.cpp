class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i=0, j=0;
        while(i < n && j < m){
            int a = nums1[i], b = nums2[j];
            if(a == b) return a;
            else if(a > b) j++;
            else i++;
        }
        return -1;
    }
};