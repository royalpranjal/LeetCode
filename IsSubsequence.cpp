class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.size() > t.size()){
            return false;
        }
        
        map<char, vector<int> > myMap;
        
        for(int i = 0; i < t.size(); i++){
            myMap[t[i]].push_back(i);
        }
        
        int i = 0, curr = -1;
        
        while(i < s.size()){
            if(myMap.find(s[i]) == myMap.end()){
                return false;
            }
            else{
                vector<int> temp = myMap[s[i]];
                int j = 0;
                while(j < temp.size()){
                    if(temp[j] > curr){
                        curr = temp[j];
                        break;
                    }
                    j++;
                }
                if(j == temp.size()){
                    return false;
                }
            }
            i++;
        }
        
        
        return true;
        
        // long long int rows = s.size(), cols = t.size();
        
        // vector<vector<bool> > temp(rows+1, vector<bool>(cols+1, false));
        
        // for(long long int i = 0; i <= cols; i++){
        //     temp[0][i] = true;
        // }
        
        // for(long long int i = 1; i <= rows; i++){
        //     for(long long int j = 1; j <= cols; j++){
        //         if(s[i-1] != t[j-1]){
        //             temp[i][j] = temp[i][j-1];
        //         }
        //         else{
        //             temp[i][j] = temp[i-1][j-1] || temp[i][j-1];
        //         }
        //     }
        // }
        
        // return temp[rows][cols];
    }
};
