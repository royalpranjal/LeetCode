class Solution {
public:
    void make(vector<vector<int> >& image, int currR, int currC, int currColor, int newColor){
        int rows = image.size(), cols = image[0].size();
        
        if(currR >= rows || currR < 0 || currC >= cols || currC < 0){
            return;
        }
        else if(image[currR][currC] != currColor || image[currR][currC] == newColor){
            return;
        }
        
        image[currR][currC] = newColor;
        make(image, currR+1, currC, currColor, newColor);
        make(image, currR-1, currC, currColor, newColor);
        make(image, currR, currC+1, currColor, newColor);
        make(image, currR, currC-1, currColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        make(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};
