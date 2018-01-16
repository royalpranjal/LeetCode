class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int n = A.size();
        
        if(n < 3){
            return 0;
        }
        
        int start = 0, sol = 0;
        
        while(start < n - 2){
            int diff = A[start+1] - A[start];
            for(int i = start + 2; i < n; i++){
                if(A[i] - A[i-1] == diff){
                    sol++;
                }
                else{
                    break;
                }
            }
            start++;
        }
        
        return sol;
    }
};
