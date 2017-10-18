class Solution {
public:
    int countBinarySubstrings(string s) {
        // int i = 0, n = s.size(), ans = 0;
        
        // O(n^2) algorithm
        // while(i < n){
//             bool one = false;
//             int count = 1;
            
//             if(s[i] == '1'){
//                 one = true;
//             }
            
//             int j = i-1;
            
//             while(j >= 0){
//                 if(one){
//                     if(s[j] != '1'){
//                         break;
//                     }
//                     count++;
//                 }
//                 else{
//                     if(s[j] != '0'){
//                         break;
//                     }
//                     count++;
//                 }
//                 j--;
//             }
            
//             while(j >= 0){
//                 if(one){
//                     if(s[j] == '1'){
//                         break;
//                     }
//                     count--;
//                 }
//                 else{
//                     if(s[j] == '0'){
//                         break;
//                     }
//                     count--;
//                 }
//                 j--;
//             }
            
//             if(count <= 0){
//                 ans++;
//             }
            
//             i++;
//         }
        
        // O(n) algorithm
        
        int i = 0, n = s.size(), ans = 0;
    
        while(i < n){
            char curr = s[i];
            int j = i;
            
            while(j < n && s[j] == curr){
                j++;
            }
            
            int k = j;
            j--;
            
            while(k < n && s[k] != curr){
                k++;
            }
            
            ans += min(j-i+1, k-j-1);
            
            i = j+1;
        }    
    
        return ans;
    }
};
