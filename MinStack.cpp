class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> minSt;
    stack<int> st;
    
    MinStack() {
        while(!st.empty()){
            st.pop();
            minSt.pop();
        }
    }
    
    void push(int x) {
        st.push(x);
        if(minSt.empty()){
            minSt.push(x);
        }
        else{
            if(minSt.top() < x){
                minSt.push(minSt.top());
            }
            else{
                minSt.push(x);
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!minSt.empty()){
            return minSt.top();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
