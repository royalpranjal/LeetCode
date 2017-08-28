class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 0;
        
        while(i < n){
            while((nums[i]-1 != i) && (nums[i] != nums[nums[i]-1])){
                swap(nums[i], nums[nums[i]-1]);
            }
            i++;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(nums[i]-1 != i){
                ans.push_back(nums[i]);
            }
        }
        
        if(ans.size()){
            sort(ans.begin(), ans.end());
        }
        
        return ans;
    }
};
