class Solution {
public:
    void make(vector<int> temp, int curr, int n, int k, vector<vector<int> >& ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        else if(curr > n){
            return;
        }
        
        for(int i = curr; i <= n; i++){
            vector<int> t(temp);
            t.push_back(i);
            make(t, i+1, n, k, ans);
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        
        for(int i = 1; i <= n; i++){
            vector<int> temp(1, i);
            make(temp, i+1, n, k, ans);
        }    
        
        return ans;
    }
};
