class Solution {
public:
    bool binarySearch(vector<vector<int> > matrix, int row, int target){
        int end = matrix[row].size()-1;
        int start = 0;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return 0;
        }
        
        int startRow = 0, endRow = matrix.size()-1, cols = matrix[0].size()-1;
        
        while(startRow <= endRow){
            int mid = startRow + (endRow-startRow)/2;
            if(matrix[mid][0] <= target && matrix[mid][cols] >= target){
                return binarySearch(matrix, mid, target);
            }
            else if(matrix[mid][0] > target){
                endRow = mid-1;
            }
            else if(matrix[mid][cols] < target){
                startRow = mid+1;
            }
        }
        
        return false;
    }
};
