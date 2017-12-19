class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> last(n+1, 0);
        vector<int> slast(n+1, 0);
        
        last[1] = cost[0];
        slast[1] = cost[0];
        
        for(int i = 2; i <= n; i++){
            last[i] = cost[i-1] + min(last[i-1], slast[i-1]);
            slast[i] = cost[i-1] + min(last[i-2], slast[i-2]);
        }
        
        return min(min(last[n], last[n-1]), min(slast[n], slast[n-1]));
    }
};
