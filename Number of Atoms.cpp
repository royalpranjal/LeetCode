class Solution {
public:
    int getNum(string s, int& i, int n){
        string countString = "";
            
        while(i < n && isdigit(s[i])){
            countString += s[i];
            i++;
        }
        
        if(countString.size()){
            return stoi(countString);
        }
        
        return 1;
    }
    
    string parse(string s, int& i, int& count){
        int n = s.size();
        
        string ans = "";
        
        do{
            ans += s[i];
            i++;
        }while(i < n && !isdigit(s[i]) && (s[i] <= 122 && s[i] >= 97));
        
        count = getNum(s, i, n);
        
        return ans;
    }
    
    void insertInMap(map<string, int>& m, string s, int count){
        if(m.find(s) == m.end()){
            m[s] = count;
        }
        else{
            m[s] += count;
        }
    }
    
    void printMap(map<string, int>& m){
        map<string, int> :: iterator it = m.begin();
        
        while(it != m.end()){
            cout << it->first << " : " << it->second << endl;
            it++;
        }
        
        cout << endl;
    }
    
    int getEnd(string s, int start, int end){
        int bracket = 0;
        
        while(start < end){
            if(s[start] == '('){
                bracket++;
            }
            else if(s[start] == ')'){
                if(bracket == 0){
                    return start;
                }
                bracket--;
            }
            start++;
        }
        
        return start;
    }
    
    void addMap(map<string, int>& ans, map<string, int> tempAns, int mul){
        map<string, int> :: iterator it = tempAns.begin();
        
        while(it != tempAns.end()){
            insertInMap(ans, it->first, (it->second)*mul);
            it++;
        }
    }
    
    map<string, int> check(string s, int start, int end){
        map<string, int> ans;
        
        while(start < end){
            if(s[start] == '('){
                int tempEnd = getEnd(s, start+1, end);
                map<string, int> tempAns = check(s, start+1, tempEnd);
                start = tempEnd+1;
                addMap(ans, tempAns, getNum(s, start, end));
            }
            else{
                int count = 1;
                string temp = parse(s, start, count);
                insertInMap(ans, temp, count);
                // printMap(ans);
            }
        }
        
        return ans;
    }
    
    string makeAns(map<string, int>& m){
        string ans = "";
        
        map<string, int> :: iterator it = m.begin();
        
        while(it != m.end()){
            ans += it->first;
            if(it->second != 1){
                ans += to_string(it->second);
            }
            it++;
        }
        
        return ans;
    }
    
    string countOfAtoms(string formula) {
        int n = formula.size(), i = 0;
        
        map<string, int> ans = check(formula, i, n);
        
        return makeAns(ans);
    }
};
