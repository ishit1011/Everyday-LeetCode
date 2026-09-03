class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int totalOddCnt = 0, totalEvenCnt = 0, smallestOdd = INT_MAX, smallestEven = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0 && nums[i] < smallestEven) smallestEven = nums[i];
            else if(nums[i] % 2 != 0 && nums[i] < smallestOdd) smallestOdd = nums[i];
        }

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                totalEvenCnt++;
                if(nums[i] > smallestOdd) totalOddCnt++;
            }
            else{
                totalOddCnt++;
                if(nums[i] > smallestOdd) totalEvenCnt++;
            }
        }

        // cout<<"\n\ntotalOddcnt = "<<totalOddCnt<<" totalEvenCnt = "<<totalEvenCnt<<endl;
        return (totalOddCnt == n || totalEvenCnt == n);
    }
};