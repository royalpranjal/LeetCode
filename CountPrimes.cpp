class Solution {
public:
    int countPrimes(int n) {
        vector<int> temp(n+1, 1);
        
        temp[0] = 0, temp[1] = 0;
        
        int ans = 0;
        
        for(int i = 2; i < temp.size(); i++){
            if(temp[i] == 1){
                ans++;
                for(int j = 2; i*j < temp.size(); j++){
                    temp[i*j] = 0;
                }    
            }
        }
        
        if(temp[n] == 1){
            ans--;
        }
        
        return ans;
    }
};
