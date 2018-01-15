class Solution {
public:
//     BRUTE FORCE (RECURSION)
//     void make(string s, vector<int>& ans, int curr, vector<int> tempAns, map<char, bool> m){
//         int n = s.size();
        
//         if(curr == n){
//             if(tempAns.size() > ans.size()){
//                 ans = tempAns;
//             }
//             return;
//         }
        
//         map<char, bool> tempM = m;
        
//         for(int i = curr; i < n; i++){
//             if(m.find(s[i]) != m.end()){
//                 return;
//             }
//             tempM[s[i]] = true;
//             vector<int> temp = tempAns;
//             temp.push_back(i - curr + 1);
//             make(s, ans, i + 1, temp, tempM);
//         }
        
//     }
    
    vector<int> partitionLabels(string S) {
        // BRUTE FORCE (RECURSION)
        // vector<int> ans;
        // vector<int> temp;
        // map<char, bool> m;
        // make(S, ans, 0, temp, m);
        
        // O(n) solution
        int i = 0, n = S.size();
        
        vector<int> ans;
        map<char, int> m;
        
        for(int i = 0; i < n; i++){
            m[S[i]] = i;
        }
        
        while(i < n){
            int maxi = m[S[i]], j = i;
            
            while(j <= maxi){
                maxi = max(maxi, m[S[j]]);
                j++;
            }
            
            ans.push_back(j - i);
            i = j;
        }
        
        return ans;
    }
};
