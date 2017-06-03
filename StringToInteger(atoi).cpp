class Solution {
public:
    int myAtoi(string str) {
        int i = 0, n = str.size(), flag = 0;
        
        long int ans = 0;
        
        while(isspace(str[i]) && i < n){
            i++;
        }
        
        if(i == n){
            return ans;
        }
        
        if(str[i] == '-'){
            flag = 1;
            i++;
        }
        else if(str[i] == '+'){
            i++;
        }
            
        string temp = "";
        
        while(i < n){
            if(!isdigit(str[i])){
                break;
            }
            temp = temp + str[i];
            i++;
        }
        
        if(!temp.size()){
            return ans;
        }
        
        if(temp.size() > 10){
            if(flag){
                return INT_MIN;
            }
            return INT_MAX;
        }
        
        ans = stol(temp);
        
        if(flag){
            ans = -ans;
        }
        
        if(ans > INT_MAX){
            return INT_MAX;
        }
        
        if(ans < INT_MIN){
            return INT_MIN;
        }
        
        return (int)ans;
    }
};
