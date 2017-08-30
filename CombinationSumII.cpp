class Solution {
public:
    void make(vector<int>& candidates, int curr, int target, long int total, vector<int> temp, vector<vector<int> >& ans, map<vector<int>, bool>& m){
        int n = candidates.size();
        if(total == target){
            if(m.find(temp) == m.end()){
                ans.push_back(temp);
                m[temp] = true;    
            }
            return;
        }
        else if(curr == n){
            return;
        }
        else if(total > target){
            return;
        }
        
        for(int i = curr; i < n; i++){
            vector<int> t = temp;
            t.push_back(candidates[i]);
            make(candidates, i+1, target, total+candidates[i], t, ans, m);
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        sort(candidates.begin(), candidates.end());
        map<vector<int>, bool> m;
        vector<int> temp;
        make(candidates, 0, target, 0, temp, ans, m);
        return ans;
    }
};
