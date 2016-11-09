class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1 || nums.size() == 0){
            return nums;
        }
        
        deque<int> q;
        
        vector<int> sol;
        
        int i = 0;
        
        while(i < k){
            while((!q.empty()) &&  (nums[i] >= nums[q.back()])){
                q.pop_back();
            }
            q.push_back(i);
            i++;
        }
        
        sol.push_back(nums[q.front()]);
        
        while(i < nums.size()){
            if((!q.empty()) && ((i - q.front()) >= k)){
                q.pop_front();
            }
            while((!q.empty()) && (nums[q.back()] <= nums[i])){
                q.pop_back();
            }
            q.push_back(i);
            sol.push_back(nums[q.front()]);
            i++;
        }
        
        return sol;
    }
};
