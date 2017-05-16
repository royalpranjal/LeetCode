class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        
        vector<vector<int> > temp(n1+1, vector<int>(n2+1, 0));
        
        for(int i = 1; i <= n1; i++){
            temp[i][0] = temp[i-1][0] + 1; 
        }
        
        for(int j = 1; j <= n2; j++){
            temp[0][j] = temp[0][j-1] + 1;
        }
        
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(word1[i-1] == word2[j-1]){
                    temp[i][j] = temp[i-1][j-1];
                }
                else{
                    temp[i][j] = min(temp[i-1][j-1] + 2, min(temp[i-1][j] + 1, temp[i][j-1] + 1));
                }
            }
        }
        
        return temp[n1][n2];
    }
};
