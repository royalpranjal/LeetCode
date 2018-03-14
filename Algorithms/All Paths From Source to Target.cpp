class Solution {
public:
    void dfs(vector<vector<int> >& graph, int curr, vector<int> temp, vector<vector<int> >& ans, int target){
        temp.push_back(curr);
        
        if(curr == target){
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < graph[curr].size(); i++){
            dfs(graph, graph[curr][i], temp, ans, target);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > ans;
        
        vector<int> temp;
        dfs(graph, 0, temp, ans, graph.size() - 1);
        
        return ans;
    }
};
