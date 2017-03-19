class Solution {
public:
    int get(vector<int> temp, int start, int end){
        int len = temp.size();
        
        for(int i = 0; i < len; i++){
            if(temp[i] > start){
                return temp[i];
            }
        }
        
        return end;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        
        int i = 0, n = s.size();
        
        map<char, vector<int>> m;
        
        for(int i = 0; i < n; i++){
            m[s[i]].push_back(i);
        }
        
        while(i < d.size()){
            bool found = true;
            
            int len = d[i].size(), start = -1;
            
            for(int j = 0; j < len; j++){
                char c = d[i][j];
                if(m.find(c) == m.end()){
                    found = false; 
                    break;
                }
                else{
                    start = get(m[c], start, n);
                    if(start == n){
                        found = false;
                        break;
                    }
                }
            }
            
            if(found){
                if(ans.size() < len){
                    ans = d[i];
                }
                else if(ans.size() == len){
                    if(ans > d[i]){
                        ans = d[i];
                    }
                }
            }
            
            i++;
        }
            
        return ans;
    }
};
