class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        int j = 0;
        int sol = INT_MIN, temp = 0;
        
        while(j < nums.size()){
            temp = temp + nums[j];
            sol = max(sol, temp);
            if(temp < 0){
                temp = 0;
            }
            j++;
        }
        
        return sol;
    }
};
