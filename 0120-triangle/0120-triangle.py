class Solution:
    def solveMem(self, triangle, row, col, dp):
        if (row >= len(triangle)):
            return 0
        if (len(triangle) == 1):
            return triangle[row][col]
        # for getting previously calculated values
        if (dp[row][col] != -1):
            return dp[row][col]
        
        # caluclate the dp[row][col] recursively
        dp[row][col] = triangle[row][col] + min(self.solveMem(triangle, row+1, col, dp), 
                                                self.solveMem(triangle, row+1, col+1, dp))
        return dp[row][col]

    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # Initialize a 2d list of same size, with value -1
        dp = [[-1 for _ in range(len(triangle))] for _ in range(len(triangle))]
        return self.solveMem(triangle, 0, 0, dp)
