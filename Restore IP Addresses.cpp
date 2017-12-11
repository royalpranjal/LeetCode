class Solution {
public:
    bool checkValidIPPart(string temp){
        if(temp.size() > 0 && temp.size() <= 3){
            if(stoi(temp) <= 255){
                if(temp.size() == 1){
                    return true;    
                }
                else if(temp[0] == '0'){
                    return false;
                }
                return true;
            }
        }
        
        return false;
    }
    
    bool checkValidIP(string s){
        int dots = 0;
        string temp = "";
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.'){
                if(!checkValidIPPart(temp)){
                    return false;
                }
                
                temp = "";
                dots++;
            }
            else{
                temp += s[i];
            }
        }
    
        return dots == 3 && checkValidIPPart(temp);
    }
    
    void make(string s, vector<string>& ans, string finalStr, string last, int curr, int dots, map<string, bool>& m){
        int n = s.size();
        
        if(curr == n){
            if(checkValidIP(finalStr) && m.find(finalStr) == m.end()){
                ans.push_back(finalStr);
                m[finalStr] = true;
            }
            return;
        }
        
        if(dots > 3){
            return; 
        }
        else if(last.size() != 0 && !checkValidIPPart(last)){
            return;
        }
        
        make(s, ans, finalStr + s[curr], last + s[curr], curr+1, dots, m);
        make(s, ans, finalStr + s[curr] + ".", "", curr+1, dots+1, m);   
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        map<string, bool> m;
        
        make(s, ans, "", "", 0, 0, m);
        return ans;
    }
};
