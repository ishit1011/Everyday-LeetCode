class Solution {
public:
    stack<char> stk;
    int scoreReturn(string s, char one, char two, int add){
        int n = s.size();
        int score = 0;
        for(int i=0; i<n; i++){
            if(!stk.empty() && stk.top()==one && s[i] == two){
                stk.pop();
                score += add;
                continue;
            }
            else{
                stk.push(s[i]);
            }
        }
        return score;
    }
    int maximumGain(string s, int x, int y) {
        char first, second;
        int firstScore = max(x,y), secondScore = min(x,y);
        if(x > y){
            first = 'a';
            second = 'b';
        }
        else{
            first = 'b';
            second = 'a';
        }
        int total = 0;
        total += scoreReturn(s,first,second,firstScore);
        string temp = "";
        while(!stk.empty()){
            cout<<stk.top();
            temp += stk.top();
            stk.pop();
        }
        reverse(temp.begin(),temp.end());
        cout<<"temp : "<<temp<<endl;
        total += scoreReturn(temp,second,first,secondScore);
        return total;
    }
};