class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(), i = 0;
        
        while(i < n){
            while(nums[i]-1 != i){
                if(nums[nums[i]-1] == nums[i]){
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
            i++;
        }
        
        vector<int> ans;
        
        i = 0;
        
        while(i < n){
            if(nums[i]-1 != i){
                ans.push_back(i+1);
            }
            i++;
        }
        
        return ans;
    }
};
