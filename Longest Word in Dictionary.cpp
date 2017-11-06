class Solution {
public:
    struct comp{
        bool operator()(string& a, string& b){
            if(a.size() == b.size()){
                for(int i = 0; i < a.size(); i++){
                    if(a[i] < b[i]){
                        return true;
                    }
                    else if(a[i] > b[i]){
                        return false;
                    }
                }
            }
            
            return a.size() > b.size();
        }  
    };
    
    string getsubstr(string s){
        int n = s.size();
        
        string ans = "";
        
        for(int i = 0; i < n-1; i++){
            ans += s[i];
        }
        
        return ans;
    }
    
    
    string longestWord(vector<string>& words) {
        map<string, bool> m;
        
        int n = words.size();
        
        for(int i = 0; i < n; i++){
            m[words[i]] = true;
        }
        
        sort(words.begin(), words.end(), comp());
        
        // for(int i = 0; i < n; i++){
        //     cout << words[i] << " ";
        // }
        
        for(int i = 0; i < n; i++){
            string temp = getsubstr(words[i]);
            while(temp.size() != 0 && m.find(temp) != m.end()){
                temp = getsubstr(temp);
            }
            
            if(temp.size() == 0){
                return words[i];
            }
        }
        
        return "";
    }
};
