class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,bool> rowMp, colMp;
        //Rows check
        for(int i=0; i<9; i++){
            vector<int> numsRow(10,0);
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    numsRow[val]++;
                    if(numsRow[val] == 2){
                        rowMp[i] = false;
                        break;
                    }
                }
                rowMp[i] = true;
            }
        }
        // Cols check
        for(int j=0; j<9; j++){
            vector<int> numsCol(10,0);
            for(int i=0; i<9; i++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    numsCol[val]++;
                    if(numsCol[val] == 2){
                        colMp[j] = false;
                        break;
                    }
                }
                colMp[j] = true;
            }
        }
        // Box-1
        vector<int> nums(10,0);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        // Box-2
        for(int i=0; i<3; i++){
            for(int j=3; j<6; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
            for(int k=0; k<nums.size(); k++){
                cout<<nums[k]<<" ";
            }
            cout<<endl;
        }
        nums.assign(10,0);
        // Box-3
        for(int i=0; i<3; i++){
            for(int j=6; j<9; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        // Box-4
        for(int i=3; i<6; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        // Box-5
        for(int i=3; i<6; i++){
            for(int j=3; j<6; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        // Box-6
        for(int i=3; i<6; i++){
            for(int j=6; j<9; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        // Box-7
        for(int i=6; i<9; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        // Box-8
        for(int i=6; i<9; i++){
            for(int j=3; j<6; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        // Box-9
        for(int i=6; i<9; i++){
            for(int j=6; j<9; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    nums[val]++;
                    if(nums[val] == 2){
                        return false;
                    }
                }
            }
        }
        nums.assign(10,0);
        for(auto [i,j] : rowMp){
            if(j == false) return false;
        }

        for(auto [i,j] : colMp){
            if(j == false) return false;
        }
        return true;
    }
};