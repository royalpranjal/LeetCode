class Solution {
public:
    int getType(string s, int& curr){
        int n = s.size(), type = 1;
        
        while(curr < n && s[curr] != ','){
            if(!isdigit(s[curr])){
                type = 0;
            }
            curr++;
        }
        
        return type;
    }
    
    bool isValidSerialization(string preorder) {
        int n = preorder.size(), i = 0;
        stack<int> st;
        
        while(i < n){
            int type = getType(preorder, i);
            if(!type){
                if(i == n){
                    break;
                }
                else if(st.empty()){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(1);
            }
            
            i++;
        }
        
        return st.empty() && i >= n;
    }
};
