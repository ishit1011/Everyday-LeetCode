class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> charFrq;
        priority_queue<char> maxHp;
        for(char ch : s){
            charFrq[ch]++;
        }
        for(auto [x,y] : charFrq){
            maxHp.push(x);
        }
        string ans = "";
        while(!maxHp.empty()){
            char ch = maxHp.top();
            maxHp.pop();
            int cnt = charFrq[ch];
            int usage = min(cnt,repeatLimit);
            for(int i=0; i<usage; i++){
                ans += ch;
            }
            charFrq[ch] -= usage;
            if(charFrq[ch] > 0 && !maxHp.empty()){
                char nextCharac = maxHp.top();
                maxHp.pop();
                ans += nextCharac;
                charFrq[nextCharac]--;
                if(charFrq[nextCharac] > 0){
                    maxHp.push(nextCharac);
                }
                maxHp.push(ch);
            }
        }
        return ans;
    }
};