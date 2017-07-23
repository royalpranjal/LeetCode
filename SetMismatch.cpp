class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        long long int sqSum = 0, sum = (n*(n+1))/2;
        long long int acsqSum = 0, acSum = 0; 
        
        for(int i = 0; i < n; i++){
            acSum += nums[i];
            acsqSum += pow(nums[i], 2);
            sqSum += pow(i+1, 2);
        }
            
        cout << "sum : " << sum << ", acSum : " << acSum << ", sqSum : " << sqSum << ", acsqSum : " << acsqSum << endl; 
        
        long long int sumNo = (sqSum - acsqSum)/(sum - acSum);
        long long int diffNo = sum - acSum;
        
        cout << "sumNo : " << sumNo << ", diffNo : " << diffNo << endl;
        
        vector<int> sol;
        sol.push_back((int)(-diffNo+sumNo)/2);
        sol.push_back((int)(diffNo+sumNo)/2);
        
        return sol;
    }
};
