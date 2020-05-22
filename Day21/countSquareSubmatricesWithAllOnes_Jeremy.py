def countSquares(matrix):
    numRow = len(matrix)
    numCol = len(matrix[0])

    count = 0

    # init dp mat
    dp = [[0 for x in range(numCol)] for y in range(numRow)]
    
    for r in range(numRow):
        for c in range(numCol):
            # init first row and first col
            if r == 0 or c == 0:
                dp[r][c] = matrix[r][c]
                if matrix[r][c] == 1:
                    count += 1
            else:
                if matrix[r][c] >= 1:
                    dp[r][c] = min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1]) + 1
                    count += dp[r][c]
                    
    return count    