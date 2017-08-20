class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows = M.size();   
        
        if(!rows){
            return M;
        }
        
        int cols = M[0].size();
        
        vector<vector<int> > ans(rows, vector<int>(cols));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int curr = M[i][j], count = 1;
                if(i-1 >= 0){
                    curr += M[i-1][j];
                    count++;
                    if(j-1 >= 0){
                        curr += M[i-1][j-1];
                        count++;
                    }
                    if(j+1 < cols){
                        curr += M[i-1][j+1];
                        count++;
                    }
                }
                if(i+1 < rows){
                   curr += M[i+1][j];
                    count++;
                    if(j-1 >= 0){
                        curr += M[i+1][j-1];
                        count++;
                    }
                    if(j+1 < cols){
                        curr += M[i+1][j+1];
                        count++;
                    } 
                }
                if(j-1 >= 0){
                    curr += M[i][j-1];
                    count++;
                }
                if(j+1 < cols){
                    curr += M[i][j+1];
                    count++;
                }
                ans[i][j] = curr/count;
            }
        }
        
        return ans;
    }
};
