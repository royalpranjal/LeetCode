class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        
        int rows = matrix.size();
        
        if(rows == 0){
            return sol;
        }
        
        int cols = matrix[0].size();
        
        if(cols == 0){
            return sol;
        }
        
        int Sc = 0, Sr = 0, Ec = 0, Er = 0, count = 0;
        
        bool top = false;
        
        while(count != rows*cols){
            if(top){
                int i = Sr, j = Sc;
            
                while(i <= Er && j >= Ec){
                    sol.push_back(matrix[i][j]);
                    count++;
                    
                    i++;
                    j--;
                }    
            }
            else{
                int i = Er, j = Ec;
            
                while(i >= Sr && j <= Sc){
                    sol.push_back(matrix[i][j]);
                    count++;
                    
                    i--;
                    j++;
                }
            }
            
            top = !top;
            
            if(Sc == cols-1){
                Sr++;
            }   
            else{
                Sc++;
            }
            
            if(Er == rows-1){
                Ec++;
            }
            else{
                Er++;
            }
        }
        
        return sol;
        
    }
};
