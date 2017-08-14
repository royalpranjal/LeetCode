class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string ans = "";
        
        int i = 0, n = sentence.size();
        
        map<string, bool> m;
        
        for(int i = 0; i < dict.size(); i++){
            m[dict[i]] = true;
        }
        
        while(i < n){
            int j = i;
            string s = "";
            while(sentence[j] != ' ' && j < n){
                s += sentence[j];
                if(m.find(s) != m.end()){
                    break;
                }
                j++;
            }
            ans += s;
            ans += " ";
            i = j;
            while(sentence[i] != ' ' && i < n){
                i++;
            }
            i++;
        }
        
        ans.pop_back();
        
        return ans;
    }
};
