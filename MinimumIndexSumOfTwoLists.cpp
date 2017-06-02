class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size(), n2 = list2.size();
        
        map<string, int> m;
        
        vector<string> ans;
        
        int aInd = INT_MAX;
        
        for(int i = 0; i < n1; i++){
            m[list1[i]] = i;    
        }
        
        for(int i = 0; i < n2; i++){
            map<string, int> :: iterator it = m.find(list2[i]);
            if(it != m.end()){
                if(it->second + i < aInd){
                    if(ans.size() != 0){
                        ans.erase(ans.begin(), ans.end());
                    }
                    ans.push_back(list2[i]);
                    aInd = it->second + i;
                }
                else if(aInd == it->second + i){
                    ans.push_back(list2[i]);
                }
            }
        }
        
        return ans;
    }
};
