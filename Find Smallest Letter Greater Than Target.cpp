class Solution {
public:
    int bs(vector<char>& letters, int start, int end, int key){
        int ans = 0;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(letters[mid] > key){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }   
        
        return ans;
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        return letters[bs(letters, 0, letters.size()-1, target)]; 
    }
};
