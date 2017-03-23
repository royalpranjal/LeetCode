class Solution {
public:
    struct temp{
        int value;
        int index;
    };
    
    struct compare{
        bool operator()(temp& a, temp& b){
            if(a.value > b.value){
                return true;
            }
            return false;
        }    
    };
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> ans(n);
        
        if(n == 0){
            return ans;
        }
        
        vector<temp> t(n);
        
        for(int i = 0; i < n; i++){
            temp tt;
            tt.value = nums[i];
            tt.index = i;
            t[i] = tt;
        }
        
        sort(t.begin(), t.end(), compare());
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                ans[t[i].index] = "Gold Medal";
            }
            else if(i == 1){
                ans[t[i].index] = "Silver Medal";
            }
            else if(i == 2){
                ans[t[i].index] = "Bronze Medal";
            }
            else{
                ans[t[i].index] = to_string(i+1);
            }
        }
        
        return ans;
    }
};
