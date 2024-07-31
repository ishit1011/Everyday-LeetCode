class Solution {
public:
    /*
    int solve(vector<vector<int>>& books, int sWidth, int i, int remainingWidth, int currHt){
        if(i == books.size()) return currHt;
        int currWidth = books[i][0], currHeight = books[i][1];
        int take = INT_MAX;
        if(currWidth <= remainingWidth){
            take = solve(books, sWidth, i+1, remainingWidth-currWidth, max(currHt,currHeight));
        }
        int notTake = solve(books, sWidth, i+1, sWidth-currWidth, currHeight) + currHt;
        return min(take,notTake);
    }
    */
    int solveMem(vector<vector<int>>& books, int sWidth,int i, int remainingWidth, int currHt, vector<vector<int>> &dp){
        if(i == books.size()) return currHt;

        if(dp[i][remainingWidth] != -1){
            return dp[i][remainingWidth];
        }

        int currWidth = books[i][0], currHeight = books[i][1];
        int take = INT_MAX;
        if(currWidth <= remainingWidth){
            take = solveMem(books, sWidth, i+1, remainingWidth-currWidth, max(currHt,currHeight),dp);
        }
        int notTake = solveMem(books, sWidth, i+1, sWidth-currWidth, currHeight,dp) + currHt;
        return dp[i][remainingWidth] = min(take,notTake);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n+1,vector<int>(shelfWidth+1,-1));
        return solveMem(books, shelfWidth, 0, shelfWidth, 0,dp);
    }
};