class Solution {
public:
    int getCount(string& s, int& index){
        string count = "";
        
        while(!isspace(s[index])){
            count += s[index];
            index++;
        }
        
        index++;
        return stoi(count);
    }
    
    string splitByComma(string& s, int& index){
        string result = "";
        int tempIndex = index, len = s.size();
        
        while(tempIndex < len){
            result += s[tempIndex];
            tempIndex++;
        }
        
        while(index < len && s[index] != '.'){
            index++;
        }
        
        index++;
        return result;
    }
    
    void insertInMap(map<string, int>& domainCount, string domain, int count){
        if(domainCount.find(domain) == domainCount.end()){
            domainCount[domain] = count;
        }
        else{
            domainCount[domain] += count;
        }
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        
        map<string, int> domainCount;
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            int index = 0, length = cpdomains[i].size();
            int count = getCount(cpdomains[i], index);
            
            while(index < length){
                insertInMap(domainCount, splitByComma(cpdomains[i], index), count);
            }
        }
        
        map<string, int> :: iterator it = domainCount.begin();
        
        while(it != domainCount.end()){
            ans.push_back(to_string(it->second) + " " + it->first);
            it++;
        }
        
        return ans;
    }
};
