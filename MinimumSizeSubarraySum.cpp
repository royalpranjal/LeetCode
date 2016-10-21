class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sol = INT_MAX;
        
        int i = 0, j = -1, n = nums.size();
        int sum = 0;
        
        while(i < n && j < n){
            sum = sum + nums[i];
            i++;
            while(sum >= s && j <= i && j < n){
                sol = min(sol, i-j-1);
                j++;
                sum = sum - nums[j];
            }    
        }
    
        
        if(sol == INT_MAX){
            return 0;
        }
        
        return sol;
    }
};
