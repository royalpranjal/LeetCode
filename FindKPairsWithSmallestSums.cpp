class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > sol;    
        
        map<int, vector<pair<int, int> > > myMap;
        
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                pair<int, int> p(nums1[i], nums2[j]);
                myMap[sum].push_back(p);
            }
        }
        
        auto it = myMap.begin();
        
        while(it != myMap.end() && k > 0){
            vector<pair<int, int> > temp = it->second;
            for(int i = 0; i < temp.size(); i++){
                sol.push_back(temp[i]);
                k--;
                if(k == 0){
                    return sol;
                }
            }
            it++;
        }
        
        return sol;
    }
};
