class Solution {
public:
    struct count{
        int orig;
        int modi;
    };
    char findTheDifference(string s, string t) {
        map<char, count> myMap;
        
        for(long long int i = 0; i < s.size(); i++){
            auto it = myMap.find(s[i]);
            if(it == myMap.end()){
                myMap[s[i]].orig = 1;
                myMap[s[i]].modi = 0;
            }
            else{
                myMap[s[i]].orig++;
            }
        }
        
        for(long long int i = 0; i < t.size(); i++){
            if(myMap.find(t[i]) == myMap.end()){
                return t[i];
            }
            else{
                myMap[t[i]].modi++;
                if((myMap[t[i]].orig) < (myMap[t[i]].modi)){
                    return t[i];
                }
            }
        }
        
        return NULL;
    }
};
