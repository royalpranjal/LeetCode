class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0, curr = 1;
        
        while(curr <= n){
            n = n - curr;
            ans++;
            curr++;
        }
        
        return ans;
    }
};
