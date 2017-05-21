class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0, n = nums.size(), i = 1, j = 0;
        
        if(n == 0 || n == 1){
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        
        while(i < n){
            if(nums[i] == (nums[j] + 1)){
                while(nums[i] == (nums[j] + 1) && (i < n)){
                    ans = max(ans, i-j+1);
                    i++;
                }
            }
            else if(nums[i] == nums[j]){
                i++;
            }
            else{
                j++;
                if(j >= i){
                    i++;
                }
            }
        }
        
        return ans;
    }
};
