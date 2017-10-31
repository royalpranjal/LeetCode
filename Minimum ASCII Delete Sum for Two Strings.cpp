class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), sum1 = 0, sum2 = 0, maxi = 0;
        
        for(int i = 0; i < n1; i++){
            sum1 += s1[i];
        }
        
        for(int i = 0; i < n2; i++){
            sum2+= s2[i];
        }
        
        vector<vector<int> > check(n1+1, vector<int>(n2+1, 0));
        
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i-1] == s2[j-1]){
                    check[i][j] = max(check[i-1][j-1] + s1[i-1] + s2[j-1], max(check[i-1][j], check[i][j-1]));
                }
                else{
                    check[i][j] = max(check[i-1][j], check[i][j-1]);
                }
                // maxi = max(maxi, check[i][j]);
                // cout << check[i][j] << " ";
            }
            // cout << endl;
        }
       
        return sum1 + sum2 - check[n1][n2]; 
    }
};
