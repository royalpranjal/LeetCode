class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }
        
        vector<int> temp(n+1, 0);
        
        temp[1] = nums[0];
        temp[2] = nums[1];
        int sol = temp[2];
        
        for(int i = 3; i < temp.size(); i++){
            temp[i] = nums[i-1] + max(temp[i-2], temp[i-3]);
            sol = max(sol, temp[i]);
        }
        
        return sol;
    }
};
