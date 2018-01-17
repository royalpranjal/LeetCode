class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i = 0, buy = -1, profit = 0;
        
        while(i < n){
            if(i == n-1 && buy != -1){
                profit = profit + max(0, prices[i] - buy);
            }
            else if(buy == -1 || buy > prices[i]){
                buy = prices[i];
            }
            else if(prices[i] >= prices[i+1]){
                profit = profit + prices[i] - buy;
                buy = -1;    
            }
            i++;
        }
        
        return profit;
    }
};
