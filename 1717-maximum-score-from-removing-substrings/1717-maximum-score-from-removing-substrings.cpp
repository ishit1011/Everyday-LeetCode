class Solution {
public:
    string leftAfterDelt(string & str, string& checkStr){
        stack<char> stk;
        for(char ch : str){
           if(ch == checkStr[1] && !stk.empty() && stk.top() == checkStr[0]){
                stk.pop();
            }
            else{
                stk.push(ch);
            }
        }
        string left;
        while(!stk.empty()){
            left.push_back(stk.top());
            stk.pop();
        }
        reverse(left.begin(),left.end());
        return left;
    }
    int maximumGain(string s, int x, int y) {
        string high, low;
        if(x > y){
            high = "ab";
            low = "ba";
        } 
        else{
            high = "ba";
            low = "ab";
        } 

        int cntHigh = 0, cntLow = 0, ans = 0;
        string temp = leftAfterDelt(s,high);
        cntHigh = (s.length() - temp.length())/2;
        cout<<"cntHigh:" <<cntHigh<<endl;

        string rem = leftAfterDelt(temp,low);
        cntLow = (temp.length() - rem.length())/2;
        cout<<"cntLow:" <<cntLow;

        ans += cntHigh * max(x,y);
        ans += cntLow * min(x,y);

        return ans;
    }
};