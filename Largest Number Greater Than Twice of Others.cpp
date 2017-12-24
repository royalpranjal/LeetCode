class Solution {
public:
    void updateMaxiAndSMaxi(vector<int>& nums, int& maxi, int& smaxi, int& index){
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                smaxi = maxi;
                maxi = nums[i];
                index = i;
            }
            else if(nums[i] > smaxi){
                smaxi = nums[i];
            }
        }
    }
    
    
    int dominantIndex(vector<int>& nums) {
        int maxi = -1, smaxi = -1, ind = -1;
        updateMaxiAndSMaxi(nums, maxi, smaxi, ind);
        
        if(maxi >= 2*smaxi){
            return ind; 
        }
        
        return -1;
    }
};
