class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int sol = 0;
        
        int rows = matrix.size();
        
        if(rows == 0){
            return sol;
        }
        
        int cols = matrix[0].size();
        
        vector<vector<int> > temp(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < temp.size(); i++){
            if(matrix[i][0] == '1'){
                temp[i][0] = 1;
                sol = 1;
            }
        }
        
        for(int i = 1; i < temp[0].size(); i++){
            if(matrix[0][i] == '1'){
                temp[0][i] = 1;
                sol = 1;
            }
        }
        
        for(int i = 1; i < temp.size(); i++){
            for(int j = 1; j < temp[i].size(); j++){
                if(matrix[i][j] == '1'){
                    temp[i][j] = 1 + min(temp[i-1][j-1], min(temp[i][j-1], temp[i-1][j]));
                    sol = max(sol, temp[i][j]);
                }
            }
        }
        
        return sol*sol;
    }
};
