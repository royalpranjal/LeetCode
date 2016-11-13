class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        
        while(nums[i] != 0 && i < nums.size()){
            i++;
        }
        
        int j = i+1;
        
        while(j < nums.size()){
            if(nums[j] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
            j++;
        }
    }
};
