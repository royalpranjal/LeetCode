/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int get(vector<Employee*> employees, int num){
        for(int i = 0; i < employees.size(); i++){
            if(employees[i]->id == num){
                return i;
            }
        }
        
        return 0;
    }
    
    int dfs(vector<Employee*> employees, int id){
        int ans = employees[id]->importance;
        
        for(int i = 0; i < employees[id]->subordinates.size(); i++){
            ans += dfs(employees, get(employees, employees[id]->subordinates[i]));
        }
        
        return ans;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int i = 0, n = employees.size();
        
        while(i < n){
            if(employees[i]->id == id){
                break;
            }
            i++;
        }
        
        return dfs(employees, i);
    }
};
