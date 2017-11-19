class Solution {
public:
    bool isSelfDividing(int n){
        string s = to_string(n);
        
        for(int i = 0; i < s.size(); i++){
            if((s[i] == '0') || n%(s[i]-'0')){
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> sol;
        
        while(left <= right){
            if(isSelfDividing(left)){
                sol.push_back(left);
            }
            left++;
        }
        
        return sol;
    }
};
