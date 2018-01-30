class Solution {
public:
    vector<int> merge(vector<int> A, vector<int> B, int& count){
        int a = A.size(), b = B.size(), currA = 0, currB = 0, curr = 0;
        
        vector<int> ans(a + b);
        
        while(currA < a && currB < b){
            if(A[currA] > B[currB]){
                ans[curr] = B[currB];
                count += (a - currA);
                currB++;
            }
            else{
                ans[curr] = A[currA];
                currA++;
            }
            
            curr++;
        }
        
        while(currA < a){
            ans[curr] = A[currA];
            currA++;
            curr++;
        }
        
        while(currB < b){
            ans[curr] = B[currB];
            currB++;
            curr++;
        }
        
        return ans;
    }
    
    vector<int> mergeSort(vector<int>& A, int start, int end, int& count){
        if(start > end){
            vector<int> temp;
            return temp;
        }
        else if(start == end){
            vector<int> temp;
            temp.push_back(A[start]);
            return temp;
        }
        
        int mid = start + (end - start)/2;
        return merge(mergeSort(A, start, mid, count), mergeSort(A, mid+1, end, count), count);
    }
    
    bool isIdealPermutation(vector<int>& A) {
        int localCount = 0, globalCount = 0, n = A.size();
        
        for(int i = 0; i < n - 1; i++){
            if(A[i] > A[i+1]){
                localCount++;
            }
        }
        
        mergeSort(A, 0, n-1, globalCount);
        
        return localCount == globalCount;
    }
};
