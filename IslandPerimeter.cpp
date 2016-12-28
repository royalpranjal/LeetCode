class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, rows = grid.size();
        
        if(!rows){
            return ans;
        }
        
        int cols = grid[0].size();
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    ans = ans + 4;
                    if(j-1 >= 0){
                        if(grid[i][j-1] == 1){
                            ans = ans - 2;
                        }
                    }
                    if(i-1 >= 0){
                        if(grid[i-1][j] == 1){
                            ans = ans - 2;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
