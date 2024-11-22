class Solution {
public:
    string flipFunc(string & str){
        string ans = "";
        for(char c:str){
            if(c == '0') ans += '1';
            else ans += '0';
        }
        return ans;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<string> nums(n,"");
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                nums[i] += to_string(matrix[i][j]);
            }
        }
        int maxSimilar = 0;
        int currSimilar = 0;
        for(int i=0; i<nums.size(); i++){
            string flipped = flipFunc(nums[i]);
            currSimilar = 1;
            for(int j=0; j<nums.size(); j++){
                if(j != i && (nums[i] == nums[j] || flipped == nums[j])){
                    currSimilar++;
                }
            }
            maxSimilar = max(maxSimilar,currSimilar);
        }
        
        return maxSimilar;
    }
};