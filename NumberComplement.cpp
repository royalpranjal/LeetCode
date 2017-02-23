class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        long long int temp = 1;
        
        while(temp < num){
            if((temp & num) == 0){
                ans = ans + temp;
            }
            
            // cout << temp << " ";
            
            temp = temp << 1;
        }
        
        return ans;
    }
};
