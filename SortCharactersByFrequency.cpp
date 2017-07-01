class Solution {
public:
    struct temp{
        char c;
        int count;
    };
      
    class compare{
        public:
            bool operator () (temp a, temp b){
                if(a.count > b.count){
                    return false;
                }
                return true;
            }
    };
   
    string frequencySort(string s) {
        map<char, int> m;
        
        int i = 0, n = s.size();
        
        while(i < n){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 1;
            }
            else{
                m[s[i]]++;
            }
            
            i++;    
        }
        
        priority_queue<temp, vector<temp>, compare> q;
        
        map<char, int> :: iterator it = m.begin();
        
        while(it != m.end()){
            temp t;
            t.c = it->first;
            t.count = it->second;
            q.push(t);
            it++;
        }
        
        string ans = "";
        
        while(!q.empty()){
            temp t = q.top();
            for(int i = 0; i < t.count; i++){
                ans += t.c;
            }
            
            q.pop();
        }
        
        return ans;
    }
};
