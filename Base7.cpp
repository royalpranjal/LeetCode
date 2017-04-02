class Solution {
public:
    int getPow(int num){
        int ans = 0;
        
        while(pow(7, ans) <= num){
            if(pow(7, ans) == num){
                return ans;
            }
            ans++;
        }
        
        return max(0, ans-1);
    }

    string convertToBase7(int num) {
        string ans = "";
        
        if(num < 0){
            ans = "-";
            num = abs(num);
        }
        
        int power = getPow(num);
        
        while(power >= 0){
            int value = num/pow(7, power);
            ans = ans + to_string(value);
            num = num - value*pow(7, power);
            power--;
        }
        
        return ans;
    }
};
