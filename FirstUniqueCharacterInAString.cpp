class Solution {
public:
    struct pair{
        int index;
        int count;
    };
    int firstUniqChar(string s) {
        map<char, pair> myMap;
        
        for(int i = 0; i < s.size(); i++){
            if(myMap.find(s[i]) != myMap.end()){
                myMap[s[i]].count++;
            }
            else{
                myMap[s[i]].count = 1;
                myMap[s[i]].index = i;
            }
        }
        
        auto it = myMap.begin();
        
        int sol = INT_MAX;
        
        while(it != myMap.end()){
            if((it->second).count == 1){
                sol = min(sol, (it->second).index);
            }
            it++;
        }
        
        if(sol == INT_MAX){
            return -1;
        }
        
        return sol;
    }
};
