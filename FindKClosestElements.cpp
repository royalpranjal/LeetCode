class Solution {
public:
    int ls(vector<int>& arr, int start, int end, int key){
        while(start <= end){
            if(arr[start] > key){
                break;
            }
            start++;
        }
        
        if(start > 0){
            return start-1;
        }
        
        return 0;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        int index = ls(arr, 0, n-1, x);
        cout << "index : " << index << endl;
        
        int i = index-1, j = index, st = index, end = index;
        
        while(k){
            if(i >= 0 && j < n){
                if(abs(arr[i]-x) > abs(arr[j]-x)){
                    end = j;
                    j++;
                }
                else{
                    st = i;
                    i--;
                }
            }
            else if(i >= 0){
                st = i;
                i--;
            }
            else{
                end = j;
                j++;
            }
            k--;
        }
        
        vector<int> sol;
        
        for(int i = st; i <= end; i++){
            sol.push_back(arr[i]);
        }
        
        return sol;
    }
};
