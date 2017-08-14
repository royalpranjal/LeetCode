class Solution {
public:
    void modifyPair(pair<int, int>& p, int l, int r, int u, int d){
        p.first += r-l;
        p.second += u-d;
    }
    
    bool judgeCircle(string moves) {
        pair<int, int> p(0, 0);    
        
        int i = 0, n = moves.size();
        
        while(i < n){
            if(moves[i] == 'L'){
                modifyPair(p, 1, 0, 0, 0);
            }
            else if(moves[i] == 'R'){
                modifyPair(p, 0, 1, 0, 0);
            }
            else if(moves[i] == 'U'){
                modifyPair(p, 0, 0, 1, 0);
            }
            else{
                modifyPair(p, 0, 0, 0, 1);
            }
            i++;
        }
        
        if(p.first == 0 && p.second == 0){
            return true;
        }
        
        return false;
    }
};
