class MyCalendar {
public:
    vector<vector<int> > calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i = 0; i < calendar.size(); i++){
            if(
                (calendar[i][0] <= start && start < calendar[i][1]) || 
                (calendar[i][0] < end && end <= calendar[i][1]) || 
                (calendar[i][0] >= start && end >= calendar[i][1])
              ){
                return false;
            }
        }
        
        vector<int> interval;
        interval.push_back(start);
        interval.push_back(end);
        
        calendar.push_back(interval);
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
