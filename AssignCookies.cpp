class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children = g.size(), cookies = s.size(), ans = 0;
        
        if(children == 0 || cookies == 0){
            return ans;
        }
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        
        while(i < children && j < cookies){
            if(g[i] <= s[j]){
                ans++;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};
