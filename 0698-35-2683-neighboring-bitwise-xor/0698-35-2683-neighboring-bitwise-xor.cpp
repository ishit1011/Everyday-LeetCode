class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // original array : [a,b,c]
        // derived array : [a^b, b^c, c^a]
        // Hence combined XOR of all elements in derived array is "0"
        int n = derived.size();
        int xorSum = derived[0];
        for(int i=0; i<n-1; i++){ 
            xorSum ^= derived[i+1];
        }
        return xorSum == 0;
    }
};