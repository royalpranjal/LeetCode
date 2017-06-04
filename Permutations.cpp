class Solution {
public:
    void permute(vector<int> temp, vector<int> nums, vector<bool> visited, vector<vector<int> >& ans, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < n; i++){
            vector<bool> tempVisited = visited;
            vector<int> tempTemp = temp;    tempVisited = visited;
            if(!visited[i]){
                tempTemp.push_back(nums[i]);
                tempVisited[i] = true;
                permute(tempTemp, nums, tempVisited, ans, n);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            vector<int> temp;
            vector<bool> visited(n, false);
            
            temp.push_back(nums[i]);
            visited[i] = true;
            
            permute(temp, nums, visited, ans, n);
        }
        
        return ans;
    }
};
