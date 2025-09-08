class Solution {
public:
    bool containsZero (int x) {
        while (x != 0){ 
            if (x % 10 == 0) return true;
            x = x / 10; 
        } 
        return false; 
    }
    vector<int> getNoZeroIntegers(int n) {
        // No-Zero integer:  positive integer that does not contain any 0 in its 
        //                   decimal representation.
        int a = 1, b = n-1;
        while(a < b){
            if(!containsZero(a) && !containsZero(b)){
                return {a,b};
            }
            a++;
            b--;
        }
        return {1,1};
    }
};