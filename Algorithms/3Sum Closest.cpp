class Solution {
public:
    void makeAns(int target, int sum, int& ans){
        if(ans == INT_MAX){
            ans = sum;    
        }
        else if(abs(target - sum) < abs(target - ans)){
            ans = sum;
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            int j = i+1, k = n-1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return sum;
                }
                else if(sum < target){
                    makeAns(target, sum, ans);
                    j++;
                }
                else{
                    makeAns(target, sum, ans);
                    k--;
                }
            }
        }
        
        return ans;
    }
};
