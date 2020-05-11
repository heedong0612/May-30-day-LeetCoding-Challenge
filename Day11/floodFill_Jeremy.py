from typing import List
from enum import Enum

class Direction(Enum):
    '''Enum for Directions'''
    UP = 1
    DOWN = 2
    LEFT = 3
    RIGHT = 4

def floodFill(image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
    '''
    Perform flood fill on an image

    Calls bfs as a helper method
    '''
    oldColor = image[sr][sc]
    
    # base case
    if oldColor == newColor:
        return image
    
    image[sr][sc] = newColor
    bfs(image, sr + 1, sc, newColor, oldColor, Direction.UP)
    bfs(image, sr - 1, sc, newColor, oldColor, Direction.DOWN)
    bfs(image, sr, sc - 1, newColor, oldColor, Direction.LEFT)
    bfs(image, sr, sc + 1, newColor, oldColor, Direction.RIGHT)
    return image
        
def bfs(m: List[List[int]], r: int, c: int, newColor: int, oldColor: int, direction: Direction):
    '''
    Bread First Search to flood fill the image

    Base Case:
    - if out of bounds, or
    - current pixel != oldColor
    '''
    if checkOut(m, r, c):
        return
    if m[r][c] != oldColor:
        return

    m[r][c] = newColor

    # lol clean af
    if direction != Direction.UP:
        bfs(m, r-1, c, newColor, oldColor, Direction.DOWN)
    if direction != Direction.DOWN:
        bfs(m, r+1, c, newColor, oldColor, Direction.UP)
    if direction != Direction.LEFT:
        bfs(m, r, c+1, newColor, oldColor, Direction.RIGHT)
    if direction == Direction.RIGHT:
        bfs(m, r, c+1, newColor, oldColor, Direction.LEFT)

    # if direction == Direction.UP:
    #     bfs(m, r+1, c, newColor, oldColor, Direction.UP)
    #     bfs(m, r, c+1, newColor, oldColor, Direction.RIGHT)
    #     bfs(m, r, c-1, newColor, oldColor, Direction.LEFT)
    # elif direction == Direction.DOWN:
    #     bfs(m, r-1, c, newColor, oldColor, Direction.DOWN)
    #     bfs(m, r, c+1, newColor, oldColor, Direction.RIGHT)
    #     bfs(m, r, c-1, newColor, oldColor, Direction.LEFT)
    # elif direction == Direction.LEFT:
    #     bfs(m, r+1, c, newColor, oldColor, Direction.UP)
    #     bfs(m, r-1, c, newColor, oldColor, Direction.DOWN)
    #     bfs(m, r, c-1, newColor, oldColor, Direction.LEFT)
    # elif direction == Direction.RIGHT:
    #     bfs(m, r+1, c, newColor, oldColor, Direction.UP)
    #     bfs(m, r-1, c, newColor, oldColor, Direction.DOWN)
    #     bfs(m, r, c+1, newColor, oldColor, Direction.RIGHT)
        


def checkOut(m, r, c) -> bool:
    '''check if coordinate is out of bounds'''
    return r >= len(m) or c >= len(m[0]) or r < 0 or c < 0

if __name__ == "__main__":
    # image = [[0,0,0],[0,1,1]]
    # sr = 1
    # sc = 1
    # newColor = 1
    
    image = [[0,1,1],[0,1,1]]
    sr = 1
    sc = 1
    newColor = 1
    
    floodFill(image, sr, sc, newColor)

    