class Solution {
public:
    bool hasAlternatingBits(int n) {
        long int curr = 1;
        
        bool last1 = false;
        
        if(n & curr){
            last1 = true;
        }
        
        curr = curr << 1;
        
        while(curr <= n){
            if(curr & n){
                if(last1){
                    return false;
                }
            }
            else{
                if(!last1){
                    return false;
                }
            }
            last1 = !last1;
            curr = curr << 1;
        }
        
        return true;
    }
};
