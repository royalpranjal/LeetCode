class Solution {
public:
    void make(vector<vector<int> >& ans, vector<int>& num, vector<int> temp, int curr, int sum, int target, map<vector<int>, bool>& m){
        int n = num.size();
        if(curr >= n){
            return;
        }
        else if(sum == target){
            sort(temp.begin(), temp.end());
            if(m.find(temp) == m.end()){
                ans.push_back(temp);
            }
            m[temp] = true;
            return;
        }
        else if(sum > target){
            return;
        }
        
        for(int i = curr; i < n; i++){
            vector<int> tempp(temp);
            tempp.push_back(num[i]);
            int summ = sum + num[i];
            make(ans, num, tempp, i, summ, target, m);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        
        vector<vector<int> > ans;
        
        for(int i = 0; i < n; i++){
            vector<int> temp;
            temp.push_back(candidates[i]);
            int sum = candidates[i];
            map<vector<int>, bool> m;
            make(ans, candidates, temp, i, sum, target, m);
        }
        
        return ans;
    }
};
