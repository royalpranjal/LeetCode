class Solution {
public:
    int bs(vector<int> A, int start, int end){
        if(start <= end){
            int mid = start + (end-start)/2;
            if(A[start] <= A[mid] && A[mid] <= A[end]){
                return A[start];
            } 
            else if(A[start] >= A[mid] && A[mid] >= A[end]){
                return A[end];
            }
            else if(A[mid] <= A[end]){
                return bs(A, start, mid);
            }
            else if(A[mid] >= A[start]){
                return bs(A, mid, end);
            }
        }
        
        return 0;
    }

    int findMin(vector<int>& nums) {
        return bs(nums, 0, nums.size()-1); 
    }
};
