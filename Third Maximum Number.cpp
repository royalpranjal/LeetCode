class Solution {
public:
    void modify(long int& first, long int& second, long int& third, int num){
        if(num > first){
            third = second;
            second = first;
            first = num;
        }
        else if(num > second && num != first){
            third = second;
            second = num;
        }
        else if(num > third && num != first && num != second){
            third = num;
        }
    }
    
    int thirdMax(vector<int>& nums) {
        long int maxi = -2147483649, sMaxi = -2147483649, tMaxi = -2147483649, n = nums.size();
        
        for(int i = 0; i < n; i++){
            modify(maxi, sMaxi, tMaxi, nums[i]);
        }
        
        if(tMaxi == -2147483649){
            return (int)maxi;
        }
        
        return (int)tMaxi;
    }
};
