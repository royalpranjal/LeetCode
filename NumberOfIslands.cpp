class Solution {
public:
    int search(vector<vector<char> >& grid, vector<vector<bool> >& visited, int row, int col){
        if(row >= visited.size() || col >= visited[0].size() || row < 0 || col < 0){
            return 0;
        }
        if(grid[row][col] == '0'){
            return 0;
        }
        else{
            if(visited[row][col] == false){
                visited[row][col] = true;
                grid[row][col] = '0';
                return 1 | search(grid, visited, row+1, col) | search(grid, visited, row-1, col) | search(grid, visited, row, col+1)  | search(grid, visited, row, col-1);
            }
            return 0;
        }
        
        return 0;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        
        int sol = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    sol = sol + search(grid, visited, i, j);
                }
            }
        }
        
        return sol;
    }
};
