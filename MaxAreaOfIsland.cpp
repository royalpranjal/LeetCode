class Solution {
public:
    void check(vector<vector<int> >& grid, vector<vector<bool> >& visited, int& temp, int x, int y){
        if(x >= grid.size() || x < 0 || y < 0 || y >= grid[0].size()){
            return;
        }
        else if(grid[x][y] == 0 || visited[x][y]){
            return;
        }
        
        visited[x][y] = true;
        temp++;
        
        check(grid, visited, temp, x-1, y);
        check(grid, visited, temp, x+1, y);
        check(grid, visited, temp, x, y-1);
        check(grid, visited, temp, x, y+1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), ans = 0;
        
        if(!rows){
            return ans;
        }
        
        int cols = grid[0].size();
        
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j]){
                    int temp = 0;
                    check(grid, visited, temp, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        
        return ans;
    }
};
