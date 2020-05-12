// Donghee Lee 
// 05/11/2020

class Solution {

private:    
    vector<vector<int>> img;
    int orgcol;
    int newcol;
    
public:    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        img = image;
        orgcol = image[sr][sc];
        newcol = newColor;
        
        paintIfTouching(sr, sc);
        return img;
    }
    
    void paintIfTouching(int r, int c) {
        if (r < 0 || r > img.size()-1 || c < 0 || c > img[0].size()-1) return;
        
        // if floodfill should be applied (same group as the starting pixel)
        if (orgcol == img[r][c])  {
            
            // already painted, or originally same as the new color
            if (img[r][c] == newcol) return; 
            
            // paint to a new color
            img[r][c] = newcol;
        
            // explore touching pixels
            paintIfTouching(r-1, c);
            paintIfTouching(r+1, c);
            paintIfTouching(r, c-1);
            paintIfTouching(r, c+1);
        } else {
            return;
        }
    }
};