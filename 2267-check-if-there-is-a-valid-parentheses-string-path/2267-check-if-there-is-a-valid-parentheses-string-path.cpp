class Solution {
public:
    bool solve(vector<vector<char>>& grid, int i, int j, int balance, int m, int n, vector<vector<vector<int>>> &dp){
        // at any given point if --> cntOpenBrackets < cntClosedBrackets return false
        // by m-1, n-1 if ---> cntOpenBrackets > cntClosedBrackets return false
        // // by m-1, n-1 if ---> cntOpenBrackets ==  cntClosedBrackets return true
        if(i == m || j == n) return false;
        if(balance < 0) return false; // cntO < cntC
        // if(balance > 0 && i == m-1 && j == n-1) return false; // cntO > cntC
        if(i == m-1 && j == n-1){
            if(balance-1 == 0) return true; // cntO == cntC
            else return false;
        }
        if(dp[i][j][balance] != -1) return dp[i][j][balance];

        bool right, down;
        if(grid[i][j] == '('){
            right = solve(grid,i,j+1,balance+1,m,n,dp);
            down = solve(grid,i+1,j,balance+1,m,n,dp);
        }
        if(grid[i][j] == ')'){
            right = solve(grid,i,j+1,balance-1,m,n,dp);
            down = solve(grid,i+1,j,balance-1,m,n,dp);
        }
        dp[i][j][balance] = (right || down);

        return dp[i][j][balance];
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // - The path only ever moves down or right. [start : 0,0   end : m-1,n-1]
        // VALID paranthesis : 
        // 1. It is ().
        // 2. It can be written as AB (A concatenated with B), where A and B are valid parentheses       
        //    strings. "(()((())))" -> A = () B = ((())) 
        // 3. It can be written as (A), where A is a valid parentheses string.
        //    e.g : ((())) -> A = (())

        // RETURN : True if there exists a valid parentheses string path in the grid ELSE False.
        int maxEntries = m + n - 1;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxEntries,-1)));

        if(grid[0][0] == ')') return false;
        if(grid[m-1][n-1] == '(') return false;

        return solve(grid,0,0,0,m,n,dp);
    }
};