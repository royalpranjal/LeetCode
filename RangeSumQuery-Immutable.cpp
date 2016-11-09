class NumArray {
public:
    vector<int> temp;
    NumArray(vector<int> &nums) {
        int sum = 0;
        temp.resize(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            temp[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        if(i == 0){
            return temp[j];
        }
        return temp[j]-temp[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
