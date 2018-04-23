class Solution {
public:
    int getMinDistance(map<char, vector<int> >& dict, char key, int index){
        int minDist = INT_MAX;
        
        vector<int> vec = dict[key];
        
        for(int i = 0; i < vec.size(); i++){
            minDist = min(minDist, abs(vec[i] - index));
        }
        
        return minDist;
    }
    
    vector<int> shortestToChar(string S, char C) {
        map<char, vector<int> > dict;
        
        int n = S.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++){
            dict[S[i]].push_back(i);
        }
        
        for(int i = 0; i < n; i++){
            ans[i] = getMinDistance(dict, C, i);
        }
        
        return ans;
    }
};
