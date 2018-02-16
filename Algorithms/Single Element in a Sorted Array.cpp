class Solution {
public:
    void recursive_binary_search(vector<int>& nums, int start, int end, int& ans){
        if(start > end){
            return;
        }
        
        int mid = start + (end - start)/2;
        
        if(mid - 1 >= start && nums[mid] == nums[mid - 1]){
            if(mid%2 == 0){
                recursive_binary_search(nums, start, mid - 2, ans);
            }
            else{
                recursive_binary_search(nums, mid + 1, end, ans);
            }
        }
        else if(mid + 1 <= end && nums[mid] == nums[mid + 1]){
            if(mid%2 == 0){
                recursive_binary_search(nums, mid + 2, end, ans);
            }
            else{
                recursive_binary_search(nums, start, mid - 1, ans);
            }
        }
        else{
            ans = mid;
        }
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() - 1,ans = 0;
        recursive_binary_search(nums, 0, n, ans);
        
        return nums[ans];
    }
};
