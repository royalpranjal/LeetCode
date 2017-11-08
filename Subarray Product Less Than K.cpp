class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, sum = 1, ans = 0;
        
        while(i < n){
            sum *= nums[i];
            if(sum < k){
                i++;
            }
            else{
                if(j == i){
                    sum = 1;
                    i++;
                    j++;
                }
                else{
                    while(j < i && sum >= k){
                        ans += (i-j);
                        sum /= nums[j];
                        j++;
                    }
                    
                    sum /= nums[i];
                }
            }
        }
        
        while(j < i){
            if(sum < k){
                ans += (i-j);
            }
            sum /= nums[j];
            j++;
        }
        
        return ans;
    }
};
