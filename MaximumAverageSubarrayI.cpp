class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), sum = 0;
        
        while(i < k){
            sum += nums[i];
            i++;
        }
        
        double ans = ((double)sum)/k;
        
        while(i < n){
            sum -= nums[j];
            sum += nums[i];
            ans = max(ans, (double(sum))/k);
            j++;
            i++;
        }
        
        return ans;
    }
};
