class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        int sum = 0;
        
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "+"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.push(t1);
                st.push(t1 + t2);
                sum += st.top();
            }
            else if(ops[i] == "C"){
                sum -= st.top();
                st.pop();
            }
            else if(ops[i] == "D"){
                st.push(st.top()*2);
                sum += st.top();
            }
            else{
                st.push(stoi(ops[i]));
                sum += st.top();
            }
        }
            
        return sum;
    }
};
