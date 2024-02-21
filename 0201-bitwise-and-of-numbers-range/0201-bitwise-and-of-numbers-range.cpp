class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        while(left != right){
            left >>= 1; // right shift the number "LEFT"
            right >>= 1; // left shift the number "RIGHT"
            ans++;
        }
        return (left<<ans); // left == right 
        //add those many 0's at the end of the current element with left shift operator.
    }
};

