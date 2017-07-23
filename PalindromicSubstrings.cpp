class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), i = 0, ans = 0;
        
        while(i < n){
            // checking for odd length;
            int l = i-1, r = i+1;
            
            while(l >= 0 && r < n){
                if(s[l] != s[r]){
                    break;
                }
                ans++;
                l--;
                r++;
            }
            
            // checking for even length
            l = i-1, r = i;
            
            while(l >= 0 && r < n){
                if(s[l] != s[r]){
                    break;
                }
                ans++;
                l--;
                r++;
            }
            
            ans++;
            i++;
        }
        
        return ans;
    }
};
