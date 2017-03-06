class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int rows = picture.size(), ans = 0;
        
        if(rows == 0){
            return ans;
        }
        
        int cols = picture[0].size();
        
        map<int, int> forRow, forCol;
        
        for(int i = 0; i < rows; i++){
            int count = 0;
            for(int j = 0; j < cols; j++){
                if(picture[i][j] == 'B'){
                    count++;
                }
            }
            forRow[i] = count;
        }
        
        for(int j = 0; j < cols; j++){
            int count = 0;
            for(int i = 0; i < rows; i++){
                if(picture[i][j] == 'B'){
                    count++;
                }
            }
            forCol[j] = count;
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(picture[i][j] == 'B' && forRow[i] == 1 && forCol[j] == 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
