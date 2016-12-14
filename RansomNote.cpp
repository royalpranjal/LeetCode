class Solution {
public:
    struct pair{
        int mag;
        int note;
    };
    
    bool canConstruct(string ransomNote, string magazine) {
        map<char, pair> myMap;
        
        for(int i = 0; i < magazine.size(); i++){
            if(myMap.find(magazine[i]) == myMap.end()){
                myMap[magazine[i]].mag = 1;
            }
            else{
                myMap[magazine[i]].mag = myMap[magazine[i]].mag + 1;
            }
        }
        
        for(int i = 0; i < ransomNote.size(); i++){
            if(myMap.find(ransomNote[i]) == myMap.end()){
                return false;
            }
            else{
                myMap[ransomNote[i]].note = myMap[ransomNote[i]].note + 1;
            }
        }
        
        auto it = myMap.begin();
        
        while(it != myMap.end()){
            if((it->second).note > (it->second).mag){
                return false;
            }
            it++;
        }
        
        
        return true;
    }
};
