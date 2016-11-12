class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void makeCorrect(vector<int>& nums, int index){
        int i = index;
        while(nums[i] != i+1 && nums[i] > 0 && nums[i] <= nums.size()){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else{
                break;
            }
        }
    }
    
    int firstMissingPositive(vector<int>& nums) {
        
        int i = 0;
        
        while(i < nums.size()){
            if(nums[i] != i+1){
                makeCorrect(nums, i);
            }
            i++;
        }
        
        i = 0;
        
        while(i < nums.size()){
            if(i+1 != nums[i]){
                return i+1;
            }
            i++;
        }
        
        return nums.size()+1;
    }
};
