class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> temp(amount+1, INT_MAX);
        temp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i - coins[j] >= 0 && temp[i - coins[j]] != INT_MAX){
                    temp[i] = min(temp[i], temp[i - coins[j]] + 1);
                }
            }
        }
        
        if(temp[amount] == INT_MAX){
            return -1;
        }
        
        return temp[amount];
    }
};
