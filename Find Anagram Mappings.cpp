class Solution {
public:
    void makeMap(map<int, vector<int> >& m, vector<int>& B){
        int lenB = B.size();
        
        for(int i = 0; i < lenB; i++){
            m[B[i]].push_back(i);
        }
    }
    
    int findInMapAndChangeValue(map<int, vector<int> >& m, int num){
        int ans = -1;
        
        for(int i = 0; i < m[num].size(); i++){
            if(m[num][i] != -1){
                ans = m[num][i];
                m[num][i] = -1;
                break;
            }
        }
        
        return ans;
    }
    
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int lenA = A.size();    
        
        map<int, vector<int> > m;
        makeMap(m, B);
        
        vector<int> ans(lenA);
        
        for(int i = 0; i < lenA; i++){
            ans[i] = findInMapAndChangeValue(m, A[i]);
        }
        
        return ans;
    }
};
