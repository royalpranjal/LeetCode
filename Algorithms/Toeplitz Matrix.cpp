class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        
        if(!rows){
            return true;
        }
        
        int cols = matrix[0].size();
        
        for(int row = 0; row < rows; row++){
            int i = row + 1, j = 1;
            while(i < rows && j < cols){
                if(matrix[i][j] != matrix[i-1][j-1]){
                    return false;
                }
                
                i++;
                j++;
            }
        }
        
        for(int col = 1; col < cols; col++){
            int i = 1, j = col;
            while(i < rows && j < cols){
                if(matrix[i][j] != matrix[i-1][j-1]){
                    return false;
                }
                
                i++;
                j++;
            }
        }
        
        
        return true;
    }
};
