class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0, i = 0, n = nums.size();
        
        if(n == 0){
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        
        while(i < n){
            bool same = false;
            
            while((i+1 < n) && (nums[i] == nums[i+1])){
                same = true;
                i++;
            }
            
            if(k == 0){
                if(same){
                    ans++;
                }
            }
            else{
                int j = i+1;
            
                while(j < n){
                    bool found = false;
                    while(nums[j] == (nums[i] + k)){
                        found = true;
                        j++;
                    }
                    
                    if(found){
                        ans++;
                        break;
                    }
                    
                    j++;
                }
            }
            
            i++;
        }
        
        return ans;
    }
};
