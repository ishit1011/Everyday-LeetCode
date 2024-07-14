class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> stk;
        vector<int> ans(n,n);
        
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && stk.top().first >= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top().second;
            }
            stk.push({heights[i],i});
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> stk;
        vector<int> ans(n,-1);
        
        for(int i=0; i<n; i++){
            while(!stk.empty() && stk.top().first >= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top().second;
            }
            stk.push({heights[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ansPrev = prevSmaller(heights);
        vector<int> ansNext = nextSmaller(heights);
        cout<<"ansNext : ";
        for(int i=0; i<n; i++){
            cout<<ansNext[i]<<" ";
        }
        cout<<"\nansPrev : ";
        for(int i=0; i<n; i++){
            cout<<ansPrev[i]<<" ";
        }

        int breadth = 0;
        for(int i=0; i<n; i++){
            breadth = max(breadth,(ansNext[i]-ansPrev[i]-1)*heights[i]);
        }

        return breadth;
    }
};