class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        
        vector<int> sol;
        
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j]){
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] == nums2[j]){
                sol.push_back(nums1[i]);
                while(i+1 < nums1.size() && nums1[i] == nums1[i+1]){
                    i++;
                }
                while(j+1 < nums2.size() && nums2[j] == nums2[j+1]){
                    j++;
                }
                i++;
                j++;
            }
        }
        
        return sol;
    }
};
