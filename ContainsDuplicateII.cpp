class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int, vector<int> > myMap;
        
        for(int i = 0; i < nums.size(); i++){
            if(myMap.find(nums[i]) == myMap.end()){
                myMap[nums[i]].push_back(i);
            }
            else{
                myMap[nums[i]].push_back(i);
                vector<int> temp = myMap[nums[i]];
                if(temp[temp.size()-1] - temp[temp.size()-2] <= k){
                    return true;
                }
            }
            
        }
        
        return false;
    }
};
