class Solution:
    def memoization(self, triangle, row, col, dp):
        if (row >= len(triangle)):
            return 0
        if (len(triangle) == 1):
            return triangle[row][col]
        if (dp[row][col] != -1):
            return dp[row][col]
        # calculate the dp[row][col] recursively and store it
        dp[row][col] = triangle[row][col] + min(self.memoization(triangle, row + 1, col, dp),
                                                self.memoization(triangle, row + 1, col + 1, dp))

        return dp[row][col]
        
    
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # create a list of same size, also initializing it with -1
        dp = [[-1 for _ in range(len(triangle))] 
                for _ in range(len(triangle))]
        # function call arguments {OG_LIST, ROW, COL, DP_LIST}
        return self.memoization(triangle, 0, 0, dp)