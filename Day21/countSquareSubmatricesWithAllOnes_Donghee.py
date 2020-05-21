# Donghee Lee
# 5/21/2020
'''
Algorithm:
    1) Make a DP array of (m x n) filled with 0s
    2) Go through the original matrix and check
        a) if current val is 0, do nothing
        b) if current val is more than zero, 
            * DP[curr] = minimum of values in up, up-left, left + 1
            * increment count by that amount
    3) return count
    
'''

class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        r = len(matrix)
        c = len(matrix[0])
        
        count = 0
        dp = [[0 for x in range(c)] for y in range(r)]
        
        for i in range(r):
            for j in range(c):
                if (matrix[i][j] > 0):
                    val = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
                    dp[i][j] = val
                    count += val         
                    
        return count