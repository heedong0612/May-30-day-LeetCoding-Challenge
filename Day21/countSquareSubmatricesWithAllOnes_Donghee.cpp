// Donghee Lee
// 5/21/2020

/*
Algorithm:
    1) Make a DP array of (m x n) filled with 0s
    2) Go through the original matrix and check
        a) if current val is 0, do nothing
        b) if current val is more than zero, 
            * DP[curr] = minimum of values in up, up-left, left + 1
            * increment count by that amount
    3) return count
    
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int count = 0;
        
        vector<vector<int>> dp(r, vector<int>(c, 0)); // a new vector of r * c
        
        int temp;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] > 0) {
                    if (i * j == 0) { // will go out of bound when checking surrounding blocks if i == 0 or  j == 0
                        dp[i][j] = 1;
                        count++;
                    } else {
                        temp = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1; // up, up-left, left
                        dp[i][j] = temp;
                        count += temp;
                    }
                }
            }
        }
         return count;
    }
};