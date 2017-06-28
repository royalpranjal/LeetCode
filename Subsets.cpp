class Solution {
public:
    void make(vector<vector<int> >& ans, int curr, int n, vector<int> temp, vector<int>& nums){
        if(curr > n){
            return;
        }    
        
        ans.push_back(temp);
        
        for(int i = curr; i < n; i++){
            vector<int> sol = temp;
            sol.push_back(nums[i]);
            make(ans, i+1, n, sol, nums);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        
        ans.push_back(temp);
        
        for(int i = 0; i < nums.size(); i++){
            vector<int> sol;
            sol.push_back(nums[i]);
            make(ans, i+1, nums.size(), sol, nums);
        }
        
        return ans;
    }
};
