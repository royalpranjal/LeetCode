class Solution {
public:
    bool checkRotate(string A, string B, int i, int j, int n){
        int currI = i, currJ = j;
            
        do{
            if(A[currI] != B[currJ]){
                return false;
            }
            
            currI = (currI + 1) % n;
            currJ = (currJ + 1) % n;
        }while(currI != i && currJ != j);
        
        return true;
    }
    
    bool rotateString(string A, string B) {
        int n1 = A.size(), n2 = B.size();
        
        bool ans = false;
        
        if(n1 != n2){
            return ans;
        }
        
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                ans = ans || checkRotate(A, B, i, j, n1);
            }
        }
        
        return ans;
    }
};
