class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, bool> myMap;
        
        int sol = 0, start = 0, temp = 0, i = 0;
        
        while(i < s.size()){
            if(myMap.find(s[i]) == myMap.end()){
                myMap[s[i]] = true;
                temp++;
            }
            else{
                while(s[start] != s[i]){
                    myMap.erase(myMap.find(s[start]));
                    start++;
                    temp--;
                }
                start++;
            }
            sol = max(sol, temp);
            i++;
        }
        
        return sol;
    }
};
