class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1){
            return 0;
        }
        int parent = kthGrammar(n-1,(k+1)/2);
        if(k % 2 == 0){
            if(parent == 1) return 0;
            else return 1;
        }
        else{
            return parent;
        }
    }
};