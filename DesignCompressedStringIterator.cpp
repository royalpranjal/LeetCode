class StringIterator {
public:
    string s;
    int curr, n, count;
    char nxt;
    
    StringIterator(string compressedString) {
        s = compressedString;
        curr = 0;    
        n = compressedString.size();
        count = 0;
        nxt = ' ';
    }
    
    int getCount(string s, int& i){
        string count = "";
        
        while(i < n && isdigit(s[i])){
            count += s[i];
            i++;
        }
        
        return stoi(count);
    }
    
    char next() {
        if(hasNext()){
            if(count == 0){
                nxt = s[curr];
                curr++;
                count = getCount(s, curr);
            }
            count--;
            return nxt;
        }
        return ' ';
    }
    
    bool hasNext() {
        if(curr < n || count > 0){
            return true;
        }
        return false;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
