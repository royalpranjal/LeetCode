class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1, k = 0;
        
        LOOP:while(k <= j){
            if(nums[k] == 0){
                swap(nums[k], nums[i]);
                i++;
            }
            if(nums[k] == 2){
                swap(nums[k], nums[j]);
                j--;
                goto LOOP;
            }
            k++;
        }
        
    }
};
