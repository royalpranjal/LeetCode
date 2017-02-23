class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, temp = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                temp++;
            }
            else{
                temp = 0;
            }
            ans = max(ans, temp);
        }
        
        return ans;
    }
};
