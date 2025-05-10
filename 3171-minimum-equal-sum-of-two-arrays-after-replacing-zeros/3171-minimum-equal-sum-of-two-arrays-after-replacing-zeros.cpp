class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long arr1Sum = 0, arr2Sum = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> zero1, zero2;
        for(int i=0; i<n; i++){
            if(nums1[i] == 0){
                nums1[i]++;
                zero1.push_back(i);
            }
            arr1Sum += nums1[i];
        }
        for(int i=0; i<m; i++){
            if(nums2[i] == 0){
                nums2[i]++;
                zero2.push_back(i);
            }
            arr2Sum += nums2[i];
        }
        cout<<"cntZ1 : "<<zero1.size()<<" arr1Sum : "<<arr1Sum<<endl;
        cout<<"cntZ2 : "<<zero2.size()<<" arr2Sum : "<<arr2Sum<<endl;
        if((arr2Sum < arr1Sum && zero2.size() == 0) || (arr1Sum < arr2Sum && zero1.size() == 0)) return -1;

        return arr1Sum > arr2Sum ? arr1Sum : arr2Sum; 

    }
};