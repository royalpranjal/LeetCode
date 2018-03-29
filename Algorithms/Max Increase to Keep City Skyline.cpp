class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        
        vector<int> rowMax(rows, 0), colMax(cols, 0);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                rowMax[i] = max(rowMax[i], grid[i][j]);
            }
        }
        
        for(int j = 0; j < cols; j++){
            for(int i = 0; i < rows; i++){
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                ans += min(rowMax[i], colMax[j]) - grid[i][j];    
            }
        }
        
        return ans;
    }
};
