class Solution {
public:
    void swap(char& c, char& d){
        char temp = c;
        c = d;
        d = temp;
    }

    void reverse(string& s, int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    
    string reverseStr(string s, int k) {
        int n = s.size();
        
        for(int i = 0; i < n; i = i + 2*k){
            if((i+2*k) < n){
                reverse(s, i, i+k-1);    
            }
            else if(i+k > n){
                reverse(s, i, n-1);
            }
            else{
                reverse(s, i, i+k-1);
            }
        }
        
        return s;
    }
};
