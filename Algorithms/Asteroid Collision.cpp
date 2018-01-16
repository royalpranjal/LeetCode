class Solution {
public:
    vector<int> rev(vector<int> temp){
        int n = temp.size();
        
        for(int i = 0; i < n/2; i++){
            int t = temp[i];
            temp[i] = temp[n-i-1];
            temp[n-i-1] = t;
        }
        
        return temp;
    }
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size(), i = 0;
        
        vector<int> ans;
        stack<int> st;
        
        while(i < n){
            int num = asteroids[i], found = 0;
            while(!st.empty() && num < 0 && st.top() > 0){
                if(abs(st.top()) > abs(num)){
                    found = 1;
                    break;
                }
                else if(abs(st.top()) < abs(num)){
                    st.pop();
                }
                else{
                    found = 1;
                    st.pop();
                    break;
                }
            }

            if(!found && num){
                st.push(num);    
            }
            
            i++;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return rev(ans);
    }
};
