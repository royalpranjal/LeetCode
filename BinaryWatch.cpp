class Solution {
public:
    bool isValidTime(vector<int> top, vector<int> bot){
        int hours = 0, minutes = 0;
        
        for(int i = 0; i < 4; i++){
            hours += pow(2, i)*top[i];
        }
        
        for(int i = 0; i < 6; i++){
            minutes += pow(2, i)*bot[i];
        }
        
        return (hours <= 11) && (minutes <= 59);
    }
    
    string makeTime(vector<int> top, vector<int> bot){
        int hours = 0, minutes = 0;
        
        for(int i = 3; i >= 0; i--){
            hours += pow(2, i)*top[i];
        }
        
        for(int i = 5; i >= 0; i--){
            minutes += pow(2, i)*bot[i];
        }
        
        string mins = "";
        if(minutes < 10){
            mins = "0" + to_string(minutes);
        }
        else{
            mins = to_string(minutes);
        }
        
        return to_string(hours) + ":" + mins;
    }
    
    void check(vector<int> top, vector<int> bot, int topI, int botI, int n, vector<string>& ans, map<string, bool>& m){
        int topSize = top.size(), botSize = bot.size();
        
        if(topI == topSize && botI == botSize && n){
            return;
        }
        else if(n == 0){
            if(isValidTime(top, bot)){
                string time = makeTime(top, bot);
                if(m.find(time) == m.end()){
                    ans.push_back(time);        
                }
                m[time] = true;
            }
            return;
        }
        
        if(botI < botSize){
            for(int i = botI; i < botSize; i++){
                vector<int> temp(bot);
                temp[i] = 1;
                check(top, temp, topI, i+1, n-1, ans, m);
            }
        }
        if(topI < topSize){
            for(int i = topI; i < topSize; i++){
                vector<int> temp(top);
                temp[i] = 1;
                check(temp, bot, i+1, botI, n-1, ans, m);
            }
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        map<string, bool> m;
        
        vector<int> top(4, 0), bot(6, 0);
        check(top, bot, 0, 0, num, ans, m);
        
        return ans;
    }
};
