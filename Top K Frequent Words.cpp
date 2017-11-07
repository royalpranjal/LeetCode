class Solution {
public:
    struct temp{
        string s;
        int count;
    };
    
    struct comp{
        bool operator()(temp const& t1, temp const& t2){
            string s1 = t1.s, s2 = t2.s;
            if(t1.count == t2.count){
                int n1 = s1.size(), n2 = s2.size();

                for(int i = 0; i < min(n1, n2); i++){
                    if(s1[i] > s2[i]){
                        return true;
                    }
                    else if(s1[i] < s2[i]){
                        return false;
                    }
                }
                
                return n1 > n2;
            }
            
            return t1.count < t2.count;
        }
    };
    
    void makeMap(map<string, int>& m, vector<string>& words){
        for(int i = 0; i < words.size(); i++){
            if(m.find(words[i]) == m.end()){
                m[words[i]] = 1;
            }
            else{
                m[words[i]]++;
            }
        }
    }
    
    void insertInQueue(priority_queue<temp, vector<temp>, comp>& q, map<string, int>& m){
        map<string, int> :: iterator it = m.begin();
        
        while(it != m.end()){
            temp t;
            t.s = it->first;
            t.count = it->second;
            
            q.push(t);
            
            it++;
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        
        map<string, int> m;
        makeMap(m, words);
        
        priority_queue<temp, vector<temp>, comp> q;
        insertInQueue(q, m);
        
        vector<string> ans;
        
        while(k--){
            ans.push_back((q.top()).s);
            q.pop();
        }
        
        return ans;
    }
};
