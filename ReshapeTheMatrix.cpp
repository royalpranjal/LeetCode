class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size();
        
        if(rows == 0){
            return nums;
        }
        
        int cols = nums[0].size();
        
        if(rows*cols != r*c){
            return nums;
        }
        
        vector<vector<int> > temp(r, vector<int>(c));
        
        int row = 0, col = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(col == cols){
                    row++;
                    col = 0;
                }
                temp[i][j] = nums[row][col];
                col++;
            }
        }
        
        return temp;
    }
};
