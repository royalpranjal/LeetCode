// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        while(start <= end){
            int mid = start + (end-start)/2;
            int res = guess(mid);
            if(res == 0){
                return mid;
            }
            else if(res == 1){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return -1;
    }
};
