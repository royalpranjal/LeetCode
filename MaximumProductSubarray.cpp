class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        vector<int> maxi(n);
        vector<int> mini(n);
        
        maxi[0] = nums[0], mini[0] = nums[0];
        
        int ans = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                maxi[i] = max(nums[i], mini[i-1]*nums[i]);
                mini[i] = min(nums[i], maxi[i-1]*nums[i]);
            }
            else{
                maxi[i] = max(nums[i], maxi[i-1]*nums[i]);
                mini[i] = min(nums[i], mini[i-1]*nums[i]);
            }
            ans = max(ans, max(maxi[i], mini[i]));
        }
        
        return ans;
    }
};
