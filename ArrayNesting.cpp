class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), i = 0, ans = 0;
        
        vector<int> temp(n, 0);   
        vector<bool> visited(n, false);
        
        while(i < n){
            temp[i] = 1;
            int j = nums[i];
            while(j != i && !visited[i]){
                if(visited[j]){
                    temp[i] += temp[j];
                    break;
                }
                visited[j] = true;
                j = nums[j];
                temp[i]++;
            }
            visited[i] = true;
            ans = max(ans, temp[i]);
            i++;
        }
        
        return ans;
    }
};
