class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstCap = false;
        bool allCap = false;
        bool noneCap = true;
        
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 65 && word[i] <= 90){
                if(i == 0){
                    firstCap = true;
                }
                else if(i == 1){
                    if(firstCap){
                        allCap = true;
                        noneCap = false;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(noneCap){
                        return false;
                    }
                    else{
                        allCap = true;
                    }
                }
            }
            else{
                if(!noneCap){
                    return false;
                }
                else{
                    allCap = false;
                }
            }
        }
    
        return true;    
    }
};
