class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size(), mx = INT_MIN, mn = INT_MAX, low = -1, high = -1;       
        
        if(!n || n == 1){
            return ans;
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] >= mx){
                mx = nums[i];
            }
            else{
                high = i;
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            if(nums[i] <= mn){
                mn = nums[i];
            }
            else{
                low = i;
            }
        }
        
        if(high != -1){
            ans = abs(high - low) + 1;
        }
        
        return ans;
    }
};
