class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        
        int temp = numRows, n = s.size(), total = 2*(numRows-1);
        
        if(numRows > n || numRows == 1){
            return s;
        }
        
        for(int i = 0; i < numRows; i++){
            int gap = 2*(temp - 1);
            if(i == 0 || i == numRows - 1){
                int j = i;
                while(j < n){
                    ans += s[j];
                    j += total;
                }
            }
            else{
                int j = i, first = 1;
                while(j < n){
                    ans += s[j];
                    if(first){
                        j += 2*(temp-1);
                    }
                    else{
                        j += (total - 2*(temp-1));
                    }
                    first = !first;
                }    
            }
            
            temp--;
        }
        
        return ans;
    }
};
