class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0 || n == 1){
            return 0;
        }
        
        vector<int> temp(n, INT_MAX);
        temp[0] = 0;
        int start = 0;
        int i = 1;
        
        while(i < n){
            while(nums[start] - i + start < 0 && start < i){
                start++;
            }
            if(start == i){
                break;
            }
            temp[i] = min(temp[i], temp[start] + 1);
            i++;
        }
        
        return temp[n-1];
    }
};
