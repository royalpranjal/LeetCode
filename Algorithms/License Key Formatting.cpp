class Solution {
public:
    int getLength(string s){
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '-'){
                ans++;
            }
        }
        
        return ans;
    }
    
    string licenseKeyFormatting(string S, int K) {
        int len = getLength(S), i = 0, n = S.size();
        
        int div = (len-1)/K, first = (len-1)%K + 1;
        
        string ans = "";
        
        while(first && i < n){
            if(S[i] >= 97 && S[i] <= 122){
                ans += S[i] - 32;
                first--;
            }
            else if(S[i] != '-'){
                ans += S[i];
                first--;
            }
            i++;
        }
        
        while(div && i < n){
            ans += '-';
            int temp = K;
            while(i < n && temp){
                if(S[i] >= 97 && S[i] <= 122){
                    ans += S[i] - 32;
                    temp--;
                }
                else if(S[i] != '-'){
                    ans += S[i];
                    temp--;
                }
                i++;
            }
            div--;
        }
        
        return ans;
    }
};
