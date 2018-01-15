class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        vector<bool> temp(n+1, false);
        temp[0] = true;
        
        for(int i = 1; i <= n; i++){
            if(bits[i-1] == 0){
                if(i-1 > 0){
                    if(bits[i-2] == 0){
                        temp[i] = true;    
                    }
                    else{
                        temp[i] = temp[i-2] || temp[i-1];
                    }
                }
                else{
                    temp[i] = true;
                }
            }
            else if(bits[i-1] == 1){
                if(i-1 > 0 && bits[i-2] == 1){
                    temp[i] = temp[i-2];
                }
            }
        }
        
        for(int i = 0; i <= n; i++){
            cout << temp[i] << " ";
        }
        
        return temp[n] && temp[n-1];
    }
};
