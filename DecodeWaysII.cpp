class Solution {
public:
    int numDecodings(string s) {
        int num = pow(10, 9) + 7, n = s.size();
        
        if(n == 0){
            return 0;
        }
        if(s[0] == '0'){
            return 0;
        }
        
        vector<long int> temp(n+1, 1);
        
        if(s[0] == '*'){
            temp[1] = 9;
        }
        
        for(int i = 2; i <= n; i++){
            if(s[i-1] == '*'){
                temp[i] = temp[i-1]*9;
                temp[i] = temp[i]%num;
                if(s[i-2] == '*'){
                    temp[i] += temp[i-2]*15;
                }
                else if(s[i-2] == '1'){
                    temp[i] += temp[i-2]*9;
                }
                else if(s[i-2] == '2'){
                    temp[i] += temp[i-2]*6;
                }
                temp[i] = temp[i]%num;
            }
            else{
                if(s[i-1] == '0'){
                    if(s[i-2] == '*'){
                        temp[i] = temp[i-2]*2;
                    }
                    else if(s[i-2] == '1' || s[i-2] == '2'){
                        temp[i] = temp[i-2];    
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    temp[i] = temp[i-1];
                    temp[i] = temp[i]%num;
                    if(s[i-2] == '1'){
                        temp[i] += temp[i-2];
                    }
                    else if(s[i-2] == '2'){
                        int curr = s[i-1] - '0';
                        if(curr >= 0 && curr <= 6){
                            temp[i] += temp[i-2];
                        }
                    }    
                    else if(s[i-2] == '*'){
                        int curr = s[i-1] - '0';
                        if(curr >= 0 && curr <= 6){
                            temp[i] += temp[i-2]*2;
                        }
                        else{
                            temp[i] += temp[i-2];
                        }
                    }
                }
                temp[i] = temp[i]%num;
            }
        }
        
        return (int)temp[n];
    }
};
