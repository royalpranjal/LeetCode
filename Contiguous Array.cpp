class Solution {
public:
    struct temp{
        int first, last;    
    };
    
    
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = 0;    
        
        map<int, temp> m;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                sum--;
            }
            else{
                sum++;
            }
            
            if(m.find(sum) == m.end()){
                temp t;
                t.first = i;
                t.last = i;
                m[sum] = t;
            }
            else{
                m[sum].last = i;
            }
        }
        
        map<int, temp> :: iterator it = m.begin();
        
        while(it != m.end()){
            int currSum = it->first, first = (it->second).first, last = (it->second).last;
            
            if(currSum == 0){
                ans = max(ans, last + 1);
            }
            else{
                ans = max(ans, max(m[currSum].last - first, last - m[currSum].first));
            }
            
            it++;
        }
                          
        return ans;
    }
};
