class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> temp(num+1, 0);
        temp[1] = 1;
        
        for(int i = 2; i < temp.size(); i++){
            int n = i;
            while(n){
                if(n%2 == 0){
                    temp[i] = temp[i] + temp[n/2];
                    n = 0;
                }
                else{
                    temp[i] = temp[i] + 1;
                    n = n/2;
                }
            }
        }
        
        return temp;
    }
};
