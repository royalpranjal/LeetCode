class Solution {
public:
    void insertInMapAndVector(map<char, int>& dict, vector<int>& value, char c, int& currPos){
        if(dict.find(c) == dict.end()){
            dict[c] = currPos;
            value[currPos] = c;
            currPos++;
        }
    }
    
    string customSortString(string S, string T) {
        int slen = S.size(), tlen = T.size(), currPos = 0;
        
        map<char, int> dict;
        
        vector<int> count(26, 0);
        vector<int> value(26, 0);
        
        for(int i = 0; i < slen; i++){
            insertInMapAndVector(dict, value, S[i], currPos);
        }
        
        for(int i = 0; i < tlen; i++){
            insertInMapAndVector(dict, value, T[i], currPos);
            count[dict[T[i]]]++;
        }
        
        string ans = "";
        
        for(int i = 0; i < 26; i++){
            while(count[i]){
                ans += value[i];
                count[i]--;
            }
        }
        
        return ans;
    }
};
