class Solution {
public:
    void insertInMap(map<int, int>& m1, int num){
        if(m1.find(num) == m1.end()){
                m1[num] = 1;
            }
            else{
                m1[num]++;
            }
    }
    
    void changeAns(int& ans, int num){
        if(ans == -1){
            ans = num;
        }
        else{
            ans = min(ans, num);
        }
    }
    
    void deleteFromMap(map<int, int>& m1, int num){
        m1[num]--;
    }
    
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), degree = 0, ans = -1, j = 0;
        
        map<int, int> m1, m2;
        
        for(int i = 0; i < n; i++){
            insertInMap(m1, nums[i]);
            degree = max(degree, m1[nums[i]]);
        }
        
        for(int i = 0; i < n; i++){
            insertInMap(m2, nums[i]);
            
            if(m2[nums[i]] >= degree){
                if(m2[nums[i]] == degree){
                    while(nums[j] != nums[i]){
                        deleteFromMap(m2, nums[j]);
                        j++;
                    }
                }
                else if(m2[nums[i]] > degree){
                    while(nums[j] != nums[i]){
                        deleteFromMap(m2, nums[j]);
                        j++;
                    }
                    deleteFromMap(m2, nums[j]);
                }
                changeAns(ans, i-j+1);
            }
        }
        
        return ans;
    }
};
