class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n <= 1){
            return 0;
        }
        else if(k == 0){
            for(int i = 1; i < n; i++){
                if(nums[i] == 0 && nums[i-1] == 0){
                    return true;
                }
            }
            return false;
        }
        
        
        vector<long long int> sum(n, 0);
        
        sum[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + nums[i];
        }
        
        for(int i = 1; i < n; i++){
            if(sum[i]%k == 0){
                return true;
            }
            for(int j = i-2; j >= 0; j--){
                if((sum[i]-sum[j])%k == 0){
                    return true;
                }
            }
        }
        
        return false;
    }
};
