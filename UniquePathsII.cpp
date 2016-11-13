class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        
        if(rows == 0){
            return 0;
        }
        
        int cols = obstacleGrid[0].size();
        
        vector<vector<int> > temp(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < rows; i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            temp[i][0] = 1;
        }
        
        for(int i = 0; i < cols; i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            temp[0][i] = 1;
        }
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(obstacleGrid[i][j] != 1){
                    temp[i][j] = temp[i-1][j] + temp[i][j-1];
                }
            }
        }
        
        return temp[rows-1][cols-1];
    }
};
