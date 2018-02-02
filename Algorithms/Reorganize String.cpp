class Solution {
public:
    bool checkIfFrequenceGreaterThanLength(int freq, int n){
        return freq > (n/2 + n%2);
    }
    
    int getMaxIndex(vector<int>& freq){
        int ans = -1;
        
        for(int i = 0; i < 26; i++){
            if(freq[i]){
                if(ans == -1){
                    ans = i;
                }
                else if(freq[ans] < freq[i]){
                    ans = i;
                }
            }
        }
        
        return ans;
    }
    
    void completeString(vector<int>& freq, string& ans, int currIndex){
        int curr = 0;
        // cout << "currIndex : " << currIndex << ", freq : " << freq[currIndex] << endl;
        while(freq[currIndex]){
            if(isspace(ans[curr])){
                ans[curr] = (currIndex + 'a');
                freq[currIndex]--;
            }
            curr++;
        }
        
        for(int i = 0; i < 26; i++){
            while(freq[i]){
                if(isspace(ans[curr])){
                    ans[curr] = i + 'a';
                    freq[i]--;
                }   
                curr++;
            }
        }
    }
    
    string reorganizeString(string S) {
        int n = S.size(), curr = 0;
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i < n; i++){
            freq[S[i] - 'a']++;
        }
        
        string ans = "";
        
        for(int i = 0; i < n; i++){
            ans += " ";
        }
        
//         for(int i = 0; i < n; i++){
//             cout << freq[i] << " ";
//         }
        
        for(int i = 0; i < 26; i++){
            int maxIndex = getMaxIndex(freq);
            
            if(maxIndex == -1){
                break;
            }
            else if(checkIfFrequenceGreaterThanLength(freq[maxIndex], n)){
                return "";
            }
            
            while(freq[maxIndex]){
                ans[curr] = (maxIndex + 'a');
                curr += 2;
                
                freq[maxIndex]--;
                
                if(curr >= n){
                    completeString(freq, ans, maxIndex);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
