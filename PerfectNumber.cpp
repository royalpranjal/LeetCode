class Solution {
public:
    bool checkPerfectNumber(int num) {
        bool ans = false;
        
        int sum = 1;
        
        for(int i = 2; i <= sqrt(num); i++){
            if(num%i == 0){
                sum = sum + i;
                if(i != sqrt(num)){
                    sum = sum + num/i;
                }
            }
        }
        
        if(sum == num && num != 1){
            ans = true;
        }
        
        return ans;
    }
};
