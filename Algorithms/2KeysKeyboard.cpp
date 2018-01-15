class Solution {
public:
    int minSteps(int n) {
        vector<int> temp(n+1, INT_MAX);
        
        temp[1] = 0;
        
        for(int i = 2; i <= n; i++){
            for(int j = i-1; j >= 1; j--){
                if(i%j == 0){
                    temp[i] = min(temp[i], temp[j]+1+i/j-1);
                }
            }
        }
            
        return temp[n];
    }
};
