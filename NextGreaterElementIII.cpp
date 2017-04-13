class Solution {
public:
    int findMin(vector<int> temp, int start, int len){
        int ans = start;
        for(int i = start; i < len; i++){
            if(temp[i] > temp[start-1]){
                if(temp[i] < temp[ans]){
                    ans = i;
                }
            }
        }    
        return ans;
    }
    
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    int nextGreaterElement(int n) {
        vector<int> temp;
        
        while(n){
            temp.insert(temp.begin(), n%10);
            n = n/10;
        }
        
        bool found = false;
        
        int len = temp.size(), i = len-1;
        
        while(i > 0){
            if(temp[i] > temp[i-1]){
                found = true;
                int index = findMin(temp, i, len);
                swap(temp[i-1], temp[index]);
                sort(temp.begin()+i, temp.end());
                break;
            }
            i--;
        }
        
        if(!found){
            return -1;
        }
        
        long int ans = 0;
        
        for(int i = len-1; i >= 0; i--){
            ans = ans + temp[i]*pow(10, len-1-i);
            if(ans > INT_MAX){
                return -1;
            }
        }
        
        return (int)ans;
    }
};
