class Solution {
public:
    bool column(int col, int n, vector<string> temp){
        for(int i = 0; i < n; i++){
            if(temp[i][col] == 'Q'){
                return false;
            }
        }
        
        return true;
    }
    
    bool diagonal(int row, int col, int n, vector<string> temp){
        int trow = row, tcol = col;
        
        // left top check
        while(trow >= 0 && tcol >=0){
            if(temp[trow][tcol] == 'Q'){
                return false;
            }
            trow--;
            tcol--;
        }
        
        // right bottom check
        trow = row, tcol = col;
        while(trow < n && tcol < n){
            if(temp[trow][tcol] == 'Q'){
                return false;
            }
            trow++;
            tcol++;
        }
        
        // right top check
        trow = row, tcol = col;
        while(trow >= 0 && tcol < n){
            if(temp[trow][tcol] == 'Q'){
                return false;
            }
            trow--;
            tcol++;
        }
        
        // left bottom check
        trow = row, tcol = col;
        while(trow < n && tcol >= 0){
            if(temp[trow][tcol] == 'Q'){
                return false;
            }
            trow++;
            tcol--;
        }
        
        return true;
    }
    
    void make(vector<string> temp, int row, int n, vector<vector<string> >& ans){
        if(row == n){
            ans.push_back(temp);
        }
        
        for(int j = 0; j < n; j++){
            if(column(j, n, temp) && diagonal(row, j, n, temp)){
                vector<string> t(temp);
                t[row][j] = 'Q';
                make(t, row+1, n, ans);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        
        string s = "";
        
        for(int i = 0; i < n; i++){
            s += '.';
        }
        
        vector<string> temp(n, s);
        
        make(temp, 0, n, ans);
            
        return ans;
    }
};
