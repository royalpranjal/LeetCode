class Solution {
public:
    bool checkMain(int n){
        map<int, bool> m;
        m[2] = true;
        m[5] = true;
        m[6] = true;
        m[9] = true;
        
        if(m.find(n) != m.end()){
            return true;
        }
        
        return false;
    }
    
    bool checkExclude(int n){
        map<int, bool> m;
        m[3] = true;
        m[4] = true;
        m[7] = true;
        
        if(m.find(n) != m.end()){
            return true;
        }
        
        return false;
    }
    
    bool check(int num){
        bool main = false, exclude = false;
        
        while(num){
            if(checkMain(num%10)){
                main = true;
            }
            else if(checkExclude(num%10)){
                exclude = true;
            }
            
            num = num/10;
        }
        
        return main && !exclude;
    }
    
    int rotatedDigits(int N) {
        int ans = 0;
        
        for(int i = 1; i <= N; i++){
            if(check(i)){
                // cout << i << " ";
                ans++;
            }
        }
        
        // cout << endl;
        
        return ans;
    }
};
