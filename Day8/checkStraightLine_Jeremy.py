from typing import List
from fractions import Fraction

def checkStraightLine(coordinates: List[List[int]]) -> bool:
    '''
    Check if a bunch of coordinates make a straight line

    Constraints:
    * 2 <= coordinates.length <= 1000
    * coordinates[i].length == 2
    * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    * coordinates contains no duplicate point.
    '''
    # base case
    if len(coordinates) == 2:
        return True
    
    # get the initial difference of first two coordinates
    dx = abs(coordinates[1][0] - coordinates[0][0])
    dy = abs(coordinates[1][1] - coordinates[0][1])

    # horizontal straight line    
    if dy == 0:
        ys = [coordinates[i][1] for i in range(len(coordinates))]
        return min(ys) == max(ys)
    
    diff = Fraction(dx, dy)
    
    for i in range(2, len(coordinates)):
        currDx = abs(coordinates[i][0] - coordinates[i-1][0])
        currDy = abs(coordinates[i][1] - coordinates[i-1][1])
        currDiff = Fraction(currDx, currDy)

        # vertical straight line        
        if dx == 0:
            if currDx != 0:
                return False
            else:
                continue

        if currDiff != diff:
            return False
        
        
    return True
