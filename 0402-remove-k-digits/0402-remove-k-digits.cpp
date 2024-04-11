class Solution {
public:
    string removeKdigits(string num, int k) {
        // 1. If k == length of string
        if(k == num.size()){
            return "0";
        }
        
        stack<char> stk;
        // 2. Elements smaller than prev elements and pop the prev ones
        for(int i=0; i<num.size(); i++){
            while(k > 0 && !stk.empty() && stk.top() > num[i]){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        // 3. If "k" is still != 0 --> pop remaining "k" elements from back
        while(k > 0 && !stk.empty()){
            stk.pop();
            k--;
        }

        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());

        // 4. Remove zeroes from front
        int idx = 0;
        while(ans[idx] == '0'){
            idx++;
            cout<<idx<<" ";
        } 
        ans = ans.substr(idx);

        if(ans == "") return "0";
        return ans;
    }
};