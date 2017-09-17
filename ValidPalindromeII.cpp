class Solution {
public:
    bool check(string s, int start, int end, bool deleted){
        while(start <= end){
            if(s[start] != s[end]){
                if(deleted){
                    return false;
                }
                return check(s, start+1, end, true) || check(s, start, end-1, true);
            }
            start++;
            end--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        return check(s, 0, s.size()-1, false);   
    }
};
