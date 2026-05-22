class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int b = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[0] <= nums[mid]){
                b = mid; 
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        } 
        int s, e;
        if(target == nums[b]) return b;
        
        if(target < nums[b] && target < nums[0]){
            s = b+1;
            e = n-1;
        }
        else if(target < nums[b] && target > nums[0]){
            s = 0;
            e = b-1;
        }

        cout<<"pivot idx : "<<b<<" s = "<<s<<" e = "<<e;

        while(s <= e){
            int mid = (s+e)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};