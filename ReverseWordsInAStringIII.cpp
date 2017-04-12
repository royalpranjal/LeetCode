class Solution {
public:
    void getWord(string s, int& end){
        while((s[end] != ' ') && (end < s.size())){
            end++;
        }
    }
    
    void swap(char& c, char& d){
        char temp = c;
        c = d;
        d = temp;
    }
    
    void swap(string& s, int start, int end){
        int len = end - start;
        for(int i = 0; i < len/2; i++){
            swap(s[start+i], s[end-i-1]);
        }
    }
    
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        
        LOOP:while(i < n){
            if(isspace(s[i])){
                i++;
                goto LOOP;
            }
            int start = i, end = i;
            getWord(s, end);
            swap(s, start, end);
            // cout << "Start : " << start << " End : " << end << endl;
            i = end;
        }
        
        return s;
    }
};
