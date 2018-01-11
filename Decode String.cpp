class Solution {
public:
    int getNumber(string s, int& start, int end){
        string ans = "";
        
        while(start < end){
            if(!isdigit(s[start])){
                break;
            }
            ans += s[start];
            start++;
        }
        
        return stoi(ans);
    }
    
    string decode(string s, int& start, int end){
        string ans = "";
        
        while(start < end){
            if(isdigit(s[start])){
                int num = getNumber(s, start, end);
                start++;
                string temp = decode(s, start, end);
                
                for(int i = 0; i < num; i++){
                    ans += temp;
                }
            }
            else if(s[start] == ']'){
                break;
            }
            else{
                ans += s[start];
            }
            start++;
        }
        
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0, n = s.size();
        return decode(s, i, n);    
    }
};
