class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        // calculating the number of bits for all numbers upto R - O(R)
        vector<int> bits(R + 1, 0);
       
        for(int i = 1; i <= R; i++){
            if(i%2){
                // i is odd
                bits[i] = bits[i/2] + 1;
            }
            else{
                // is even
                bits[i] = bits[i/2];
            }
        }
        
        // marking every prime number upto R (using sieve method) - O(log log R)
        vector<int> prime(R + 1, 1);
        prime[1] = 0;
        
        for(int i = 2; i <= sqrt(R); i++){
            if(prime[i]){
                for(int j = 2; i * j <= R; j++){
                    prime[i * j] = 0;
                }
            }
        }
        
        // calculating which numbers have number of bits that are prime
        int ans = 0;
        
        for(int i = L; i <= R; i++){
            if(prime[bits[i]]){
                ans++;
            }
        }
        
        return ans;
    }
};
