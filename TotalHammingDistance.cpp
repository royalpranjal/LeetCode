class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        long int temp = 1;
        int count = 1, n = nums.size();
        
        map<int, int> m;
        
        while(temp <= INT_MAX){
            for(int i = 0; i < n; i++){
                int t = temp & nums[i];
                if(!t){
                    if(m.find(count) == m.end()){
                        m[count] = 1;
                    }
                    else{
                        m[count]++;
                    }
                }
            }
            count++;
            temp = temp << 1;
        }
        
        map<int, int> :: iterator it = m.begin();
        
        while(it != m.end()){
            ans = ans + (it->second)*(n - it->second);
            it++;
        }
        
        return ans;
    }
};
