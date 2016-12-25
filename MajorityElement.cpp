class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int maj_count = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != maj){
                maj_count--;
                if(maj_count == 0){
                    maj_count = 1;
                    maj = nums[i];
                }
            }
            else{
                maj_count++;
            }
        }
        
        return maj;
    }
};
