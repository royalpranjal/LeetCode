class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), total = 0, ans = 0;
        
        vector<int> sum(n);
        
        for(int i = 0; i < n; i++){
            total += nums[i];
            sum[i] = total;
        }
        
        for(int i = 0; i < n; i++){
            if(sum[i] == k){
                ans++;
            }
            for(int j = 0; j < i; j++){
                if(sum[i]-sum[j] == k){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};Subarray Sum Equals K
