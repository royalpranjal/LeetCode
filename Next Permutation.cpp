class Solution {
public:
    int getJustGreaterIndex(vector<int>& nums, int num, int start){
        int end = nums.size(), ans = start;
        
        while(start < end){
            if(nums[start] < nums[ans] && nums[start] > num){
                ans = start;
            }    
            start++;
        }
        
        return ans;
    }
    
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;   
        
        while(i > 0){
            if(nums[i] > nums[i-1]){
                int justGreaterIndex = getJustGreaterIndex(nums, nums[i-1], i);
                swap(nums[i-1], nums[justGreaterIndex]);
                sort(nums.begin()+i, nums.end());
                break;
            }
            i--;
        }
        
        if(i == 0){
            sort(nums.begin(), nums.end());
        }
    }
};
