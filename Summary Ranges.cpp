class Solution {
public:
    void insertInAnswerVector(vector<string>& ans, vector<int>& nums, int& last, int& i){
        if(i - 1 == last){
            ans.push_back(to_string(nums[last]));
        }
        else{
            ans.push_back(to_string(nums[last]) + "->" + to_string(nums[i-1]));
        }
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size(), last = -1;
        
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            if(i == n-1){
                if(last == -1){
                   ans.push_back(to_string(nums[i]));
                }
                else if(nums[i] != nums[i-1] + 1){
                    insertInAnswerVector(ans, nums, last, i);
                    ans.push_back(to_string(nums[i]));    
                }
                else{
                    ans.push_back(to_string(nums[last]) + "->" + to_string(nums[i]));
                }
            }
            else if(i == 0){
                last = i;
            }
            else{
                if(nums[i] != nums[i-1] + 1){
                    insertInAnswerVector(ans, nums, last, i);
                    last = i;
                }
            }
                
        }
        
        return ans;
    }
};
