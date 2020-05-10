// Donghee Lee
// 05/08/2020

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coords) {
        double slope, currSlope;
      
        if ((double)(coords[0][0] - coords[1][0]) == 0) { // delta x is 0
                slope = INT_MAX;
            } else {
                slope = (double)(coords[0][1] - coords[1][1]) / (double)(coords[0][0] - coords[1][0]);
            }
        
        for (int i = 2; i < coords.size(); i++) {
        
            if ((double)(coords[i][0] - coords[i-1][0]) == 0) { // delta x is 0
                currSlope = INT_MAX;
            } else {
                currSlope = (double)(coords[i][1] - coords[i-1][1]) / (double)(coords[i][0] - coords[i-1][0]);
            }
            if (slope != currSlope) 
                return false;
            
        }
        return true;
    }
};
