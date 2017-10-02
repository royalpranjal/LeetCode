class Solution {
public:
    int match(string A, string B, int start){
        int count = 1, i = 0, j = start;
        
        while(i < B.size()){
            if(B[i] != A[j]){
                return INT_MAX;
            }
            j++;
            i++;
            if(j == A.size() && i != B.size()){
                j = 0;
                count++;
            }
        }
            
        
        return count;
    }
    
    int repeatedStringMatch(string A, string B) {
        int ans = INT_MAX;
        
        for(int i = 0; i < A.size(); i++){
            ans = min(ans, match(A, B, i));
        }    
        
        if(ans == INT_MAX){
            return -1;
        }
        
        return ans;
    }
};
