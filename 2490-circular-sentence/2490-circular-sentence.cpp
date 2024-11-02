class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        bool firstLast = (sentence[0] == sentence[n-1]);
        bool wordChk = true;
        for(int i=0; i<n; i++){
            if(sentence[i] == ' '){
                char ch1 = sentence[i-1];
                char ch2 = sentence[i+1];
                wordChk = wordChk && (ch1 == ch2);
            }
        }
        return (firstLast && wordChk);
    }
};