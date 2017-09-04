class Solution {
public:
    void makeMap(map<int, vector<int> >& m, string s){
        int i = 0, n = s.size();
        
        while(i < n){
            m[s[i]-'0'].push_back(i);
            i++;
        }
    }
    
    void swap(char& a, char& b){
        char temp = a;
        a = b;
        b = temp;
    }
    
    bool findLarger(map<int, vector<int> >& m, int curr_index, int curr, int& index){
        int num = 9;
        
        while(curr < num){
            if(m.find(num) != m.end()){
                for(int i = m[num].size()-1; i >= 0; i--){
                    if(m[num][i] > curr_index){
                        index = m[num][i];
                        return true;    
                    }
                }
            }
            num--;
        }
        
        return false;
    }
    
    void printMap(map<int, vector<int> >& m){
        map<int, vector<int> > :: iterator it = m.begin();
        
        while(it != m.end()){
            cout << it->first << " -> ";
            for(int i = 0; i < (it->second).size(); i++){
                cout << (it->second)[i] << ",";
            }
            cout << endl;
            it++;
        }
    }
    
    int maximumSwap(int num) {
        string s = to_string(num);
        
        map<int, vector<int> > m;
        
        makeMap(m, s);
        // printMap(m);
        
        int i = 0, n = s.size();
        
        while(i < n){
            int index = -1;
            if(findLarger(m, i, s[i]-'0', index)){
                swap(s[i], s[index]);
                break;
            }
            i++;
        }
        
        // cout << "ans " << s << endl;
        return stoi(s);
    }
};
