class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 1, n = nums.size(), ans = nums[0];
        
        sort(nums.begin(), nums.end());
        
        while(i < n){
            if(nums[i] == nums[i-1]){
                ans = nums[i];
                break;
            }
            i++;
        }
        
        return ans;
    }
};
