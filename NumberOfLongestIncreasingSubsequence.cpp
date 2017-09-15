class Solution {
public:
    int check(vector<int>& nums, vector<int>& maxi, vector<int>& ways, int pos, int maximum){
        if(maximum == 1){
            return 1;
        }
        
        int ans = 0;
        
        for(int i = 0; i < pos; i++){
            if(maxi[i] == maximum-1 && nums[pos] > nums[i]){
                ans += ways[i];
            }
        }
        
        return ans;
    }
    
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_len = 1, count = 0;
        
        if(n == 0){
            return 0;
        }
        
        vector<int> maxi(n, 1);
        vector<int> ways(n, 1);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(maxi[i] < 1+maxi[j]){
                        maxi[i] = 1+maxi[j];
                        ways[i] = ways[j];
                    }
                    else if(maxi[i] == 1+maxi[j]){
                        ways[i] += ways[j];
                    }
                    
                }
            }
            max_len = max(max_len, maxi[i]);
        }
        
        for(int i = 0; i < n; i++){
            if(max_len == maxi[i]){
                count += check(nums, maxi, ways, i, max_len);
            }
        }
        
        return count;
    }
};
