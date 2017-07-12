class Solution {
public:
    void make(vector<vector<int> >& ans, vector<int>& num, vector<int> temp, int curr, int sum, int target){
        int n = num.size();
        if(curr >= n){
            return;
        }
        else if(sum == target){
            ans.push_back(temp);
            return;
        }
        else if(sum > target){
            return;
        }
        
        for(int i = curr; i < n; i++){
            vector<int> tempp(temp);
            tempp.push_back(num[i]);
            int summ = sum + num[i];
            make(ans, num, tempp, i, summ, target);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        
        vector<vector<int> > ans;
        
        for(int i = 0; i < n; i++){
            vector<int> temp;
            temp.push_back(candidates[i]);
            int sum = candidates[i];
            make(ans, candidates, temp, i, sum, target);
        }
        
        return ans;
    }
};
