class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> m;
        
        for(int i = 0; i < J.size(); i++){
            if(m.find(J[i]) == m.end()){
                m[J[i]] = 1;
            }
            else{
                m[J[i]]++;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < S.size(); i++){
            if(m.find(S[i]) != m.end()){
                ans++;
            }
        }
            
            
        return ans;
    }
};
