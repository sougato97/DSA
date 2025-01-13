class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col){
        if(row>=triangle.size())
            return 0;
        if(triangle.size()==1)
            return triangle[row][col];

        int ans=triangle[row][col]+min(solve(triangle,row+1,col), solve(triangle,row+1,col+1));
        return ans;
    }
    int solveMem(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dp){
        if(row>=triangle.size())
            return 0;
        if(triangle.size()==1)
            return triangle[row][col];

        if(dp[row][col]!=-1)
            return dp[row][col];

        dp[row][col]=triangle[row][col]+min(solveMem(triangle,row+1,col,dp), solveMem(triangle,row+1,col+1,dp));
        return dp[row][col];
    }



    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int> (triangle.size(),-1));
        // return solve(triangle, 0, 0);

        return solveMem(triangle, 0, 0,dp);
    }
};