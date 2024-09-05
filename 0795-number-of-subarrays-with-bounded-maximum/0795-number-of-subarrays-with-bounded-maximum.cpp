class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int result = 0;
        // creating a window that tracks the last valid cont. subarray
        int start = -1; 
        int last_valid = -1; // index of last valid (by itself) num
        int count = 0; // represents the count of possible cont. subarrays at the moment
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > right){
                // resetting window
                start = i;
                last_valid = -1; // have to reset completely because it must be contiguous
                count = 0;
            } else {
                if(nums[i] >= left){
                last_valid = i;
                count = last_valid - start; 
                }
                if(last_valid != -1){
                    result += count;
                }
            }
        }
        return result;
    }
};