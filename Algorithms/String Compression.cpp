class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), last = 0, i = 0;
        
        while(i < n){
            int j = i + 1;
            while(j < n && chars[j] == chars[i]){
                j++;
            }
            
            chars[last] = chars[i];
            last++;
            if(j != i + 1){
                string num = to_string(j - i);
                for(int k = 0; k < num.size(); k++){
                    chars[last] = num[k];
                    last++;
                }
                
            }
            
            i = j;
        }
        
        while(chars.size() > last){
            chars.pop_back();
        }
        
        return chars.size();
    }
};
