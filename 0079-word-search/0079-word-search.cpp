class Solution {
public:
    bool checkWord(vector<vector<char>>& board, string word, int x, int y, int idx){
        if(idx == word.size()){
            return true;
        }
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || 
            board[x][y] != word[idx]){
                return false;
        }

        char temp = board[x][y];    // Store current char
        board[x][y] = '0';          // Mark visited nodes as "0"

        bool res =  checkWord(board,word,x,y-1,idx+1) || 
                    checkWord(board,word,x,y+1,idx+1) || 
                    checkWord(board,word,x-1,y,idx+1)|| 
                    checkWord(board,word,x+1,y,idx+1);
        board[x][y] = temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool flag = checkWord(board,word,i,j,0);
                    if(flag == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};



/*
// Check left
        if (y - 1 >= 0 && board[x][y - 1] == word[idx] && 
            checkWord(board, word, x, y - 1, idx + 1)) {
            return true;
        }
        // Check right
        if (y + 1 < board[0].size() && board[x][y + 1] == word[idx] && 
            checkWord(board, word, x, y + 1, idx + 1)) {
            return true;
        }
        // Check up
        if (x - 1 >= 0 && board[x - 1][y] == word[idx] && 
            checkWord(board, word, x - 1, y, idx + 1)) {
            return true;
        }
        // Check down
        if (x + 1 < board.size() && board[x + 1][y] == word[idx] && 
            checkWord(board, word, x + 1, y, idx + 1)) {
            return true;
        }
        return false;
*/