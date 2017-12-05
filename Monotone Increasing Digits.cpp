class Solution {
public:
    int getFirstOfRepeatedIndex(string s, int i){
        while(i > 0){
            if(s[i] != s[i-1]){
                return i;
            }
            i--;
        }
        
        return i;
    }
    
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        
        int i = 0, n = s.size();
        
        while(i < n-1){
            if(s[i] > s[i+1]){
                int firstOfRepeatedIndex = getFirstOfRepeatedIndex(s, i);
                s[firstOfRepeatedIndex] = s[firstOfRepeatedIndex] - 1;
                firstOfRepeatedIndex++;
                while(firstOfRepeatedIndex < n){
                    s[firstOfRepeatedIndex] = '9';
                    firstOfRepeatedIndex++;
                }
                break;
            }
            i++;
        }
        
        cout << s << endl;
        
        return stoi(s);
    }
};
