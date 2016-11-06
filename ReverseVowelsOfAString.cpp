class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;  
        
        string st = s;
        
        LOOP:while(i < j){
            if(!(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u' 
                || st[i] == 'A' || st[i] == 'E' || st[i] == 'I' || st[i] == 'O' || st[i] == 'U')){
                i++;
                goto LOOP;
            }
            if(!(st[j] == 'a' || st[j] == 'e' || st[j] == 'i' || st[j] == 'o' || st[j] == 'u'
                || st[j] == 'A' || st[j] == 'E' || st[j] == 'I' || st[j] == 'O' || st[j] == 'U')){
                j--;
                goto LOOP;
            }   
            char temp = st[i];
            st[i] = st[j];
            st[j] = temp;
            i++;
            j--;
        }
        return st;
    }
};
