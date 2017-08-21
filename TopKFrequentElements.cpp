class Solution {
public:
    struct temp{
        int num;
        int freq;
    };
    
    struct comp{
        bool operator()(temp& a, temp& b){
            if(a.freq < b.freq){
                return true;
            }
            return false;
        }    
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        
        map<int, int> m;
        
        while(i < n){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }
            else{
                m[nums[i]]++;
            }
            i++;
        }
        
        priority_queue<temp, vector<temp>, comp> q;  
        
        map<int, int> :: iterator it = m.begin();
        
        while(it != m.end()){
            temp t;
            t.num = it->first;
            t.freq = it->second;
            q.push(t);
            it++;
        }
        
        vector<int> ans;
        
        while(k){
            ans.push_back((q.top()).num);
            q.pop();
            k--;
        }
        
        return ans;
    }
};
