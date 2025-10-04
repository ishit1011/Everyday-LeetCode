class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int l = 0, r = n-1;
        while(l < r){
            int tempArea = min(height[l],height[r]) * (r-l);
            maxArea = max(maxArea,tempArea);
            cout<<"tempArea : "<<tempArea<<" maxArea : "<<maxArea<<endl;
            if(height[l] <= height[r]){
                l++;
            }
            else r--;
        }
        return maxArea;
    }
};