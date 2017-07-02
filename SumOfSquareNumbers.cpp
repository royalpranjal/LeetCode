class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c), curr = 0;
        
        vector<int> temp(n+1);
        
        for(int i = 0; i <= n; i++){
            temp[i] = pow(curr, 2);
            curr++;
        }
        
        int i = 0, j = n;
        
        while(i <= j){
            if(temp[i] + temp[j] == c){
                return true;
            }
            else if(temp[i] + temp[j] < c){
                i++;
            }
            else{
                j--;
            }
        }
        
        return false;
    }
};
