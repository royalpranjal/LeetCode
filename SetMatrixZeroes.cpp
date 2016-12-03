class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        
        if(rows == 0){
            return;
        }
        
        int cols = matrix[0].size();
        int rf = 0, cf = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    if(i == 0 && j == 0){
                        rf = 1;
                        cf = 1;
                    }
                    else if(i == 0){
                        rf = 1;
                        matrix[0][j] = 1000007;
                    }
                    else if(j == 0){
                        cf = 1;
                        matrix[i][0] = 1000007;
                    }
                    else{
                        matrix[0][j] = 1000007;
                        matrix[i][0] = 1000007;
                    }
                }
            }
        }
        
        for(int j = 1; j < cols; j++){
            if(matrix[0][j] == 1000007){
                for(int i = 0; i < rows; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 1000007){
                for(int j = 0; j < cols; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(rf){
            for(int j = 0; j < cols; j++){
                matrix[0][j] = 0;
            }
        }
        if(cf){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
        
        return;
    }
};
