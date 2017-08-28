class Solution {
public:
    int make(int n){
        int ans = 0;
        
        while(n){
            ans += pow(n%10, 2);
            n /= 10;
        }
        
        return ans;
    }
    
    bool isHappy(int n) {
        map<int, bool> m;
        
        while(1){
            int temp = make(n);
            if(temp == 1){
                return true;
            }
            else if(m.find(n) == m.end()){
                m[n] = true;
                n = temp;
            }
            else{
                break;
            }
        }
        
        return false;
    }
};
