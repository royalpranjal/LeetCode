class MyCalendarTwo {
public:
    struct temp{
        int first, second;    
    };
    
    vector<temp> vec;
    
    
    
    MyCalendarTwo() {
        
    }
    
    struct customSort{
        bool operator()(temp& a, temp& b){
            if((a.first < b.first) || (a.first == b.first && (a.second < b.second))){
                return true;
            }
            return false;
        }
    };
    
    bool book(int start, int end) {
        int last = -1;
        
        for(int i = 0; i < vec.size(); i++){
            temp node = vec[i];
            if(
                (node.first <= start &&  start < node.second) || 
                (node.first < end && end <= node.second) || 
                (start <= node.first && node.second <= end)
                )
                {
                    if(node.first < last){
                        return false;
                    }
                    last = node.second;
                }
        }
        
        temp t;
        t.first = start;
        t.second = end;
        vec.push_back(t);
        
        sort(vec.begin(), vec.end(), customSort());
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
