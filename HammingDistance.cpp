class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        long int temp = 1;
        
        while(temp <= x || temp <= y){
            if((temp & x) != (temp & y)){
                ans++;
            }
            temp = temp << 1;
        }
        
        return ans;
    }
};
