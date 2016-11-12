class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sol = "", temp = "";
        
        if(strs.size() == 0){
            return sol;
        }
        
        int mini = INT_MAX;
        
        for(int i = 0; i < strs.size(); i++){
            if(mini > strs[i].size()){
                mini = strs[i].size();
                temp = strs[i];
            }
        }
        
        for(int i = 0; i < mini; i++){
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != temp[i]){
                    return sol;
                }    
            }
            sol = sol + temp[i];
        }
        
        return sol;
    }
};
