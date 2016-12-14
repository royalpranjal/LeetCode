class Solution {
public:
    void binarySearch(vector<int> A, int start, int end, int key, bool first, int &val){
        if(start <= end){
            int mid = start + (end-start)/2;
        
            if(A[mid] == key){
                val = mid;
                if(first){
                    binarySearch(A, start, mid-1, key, first, val);    
                }
                else{
                    binarySearch(A, mid+1, end, key, first, val);
                }
            }
            else if(A[mid] > key){
                binarySearch(A, start, mid-1, key, first, val);
            }
            else{
                binarySearch(A, mid+1, end, key, first, val);
            }
        }
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol(2, -1);
        
        int val = -1, start = -1, end = -1;
        
        binarySearch(nums, 0, nums.size()-1, target, true, val);
        start = val;
        
        binarySearch(nums, 0, nums.size()-1, target, false, val);
        end = val;
        
        if(start != -1){
            sol[0] = start;
            sol[1] = end;
        }
        
        return sol;
    }
};
