class Solution {
public:
    void shift(vector<vector<int>>& matrix, int top, int bottom, int left, int right){
        int l = left, t = top, b = bottom, r = right;
        while(l < right){
            int temp1 = matrix[top][l];
            int temp2 = matrix[t][right];
            int temp3 = matrix[bottom][r];
            int temp4 = matrix[b][left];
            matrix[t][right] = temp1;
            matrix[bottom][r] = temp2;
            matrix[b][left] = temp3;
            matrix[top][l] = temp4;
            l++;
            t++;
            r--;
            b--;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        if(matrix[0].size() != matrix.size() || matrix[0].size() == 0 || matrix.size() == 0){
            return;
        }
        
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        
        while(left < right && top < bottom){
            shift(matrix, left, right, top, bottom);
            top++;
            bottom--;
            left++;
            right--;
        }
    }
};
