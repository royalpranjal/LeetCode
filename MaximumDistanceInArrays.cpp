class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    int maxDistance(vector<vector<int>>& arrays) {
        int maxi = INT_MIN, smaxi = INT_MIN, mini = INT_MAX, smini = INT_MAX, imaxi = -1, ismaxi = -1, imini = -1, ismini = -1;
        
        for(int i = 0; i < arrays.size(); i++){
            int len = arrays[i].size();
            if(len){
                if(maxi == INT_MIN){
                    maxi = arrays[i][len-1];
                    imaxi = i;
                }
                else if(smaxi == INT_MIN){
                    smaxi = arrays[i][len-1];
                    ismaxi = i;
                    if(maxi < smaxi){
                        swap(maxi, smaxi);
                        swap(imaxi, ismaxi);
                    }
                }
                else{
                    if(arrays[i][len-1] > maxi){
                        smaxi = maxi;
                        ismaxi = imaxi;
                        maxi = arrays[i][len-1];
                        imaxi = i;
                    }
                    else if(arrays[i][len-1] > smaxi && smaxi != INT_MIN){
                        smaxi = arrays[i][len-1];
                        ismaxi = i;
                    }     
                }
                
                if(mini == INT_MAX){
                    mini = arrays[i][0];
                    imini = i;
                }
                else if(smini == INT_MAX){
                    smini = arrays[i][0];
                    ismini = i;
                    if(mini > smini){
                        swap(mini, smini);
                        swap(imini, ismini);
                    }
                }
                else{
                    if(arrays[i][0] < mini){
                        smini = mini;
                        ismini = imini;
                        mini = arrays[i][0];
                        imini = i;
                    }
                    else if(arrays[i][0] < smini && smini != INT_MAX){
                        smini = arrays[i][0];
                        ismini = i;
                    }    
                }
            }
            
            // cout << i << endl;
            // cout << "maxi : " << maxi << ", mini : " << mini << ", smaxi : " << smaxi << ", smini : " << smini << endl; 
            // cout << "imaxi : " << imaxi << ", imini : " << imini << ", ismaxi : " << ismaxi << ", ismini : " << ismini << endl; 
        }
        
        if(imaxi == imini){
            return max(abs(maxi - smini), abs(smaxi - mini));
        }
        
        return abs(maxi - mini);
    }
};
