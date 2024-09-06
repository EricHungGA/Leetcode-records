class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window approach
        // 1. calculate the sum for each window
        // if the sum is >= target, pause the window and shrink
        // it from the left until the smallest possible sum is reached
        // record the length
        // then return to expanding the right side window
        int r = 0;
        int l = 0;
        int sum = 0;
        int min_length = INT_MAX; // if its still max at the end, no possible solutions
        for(r; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){ // while loop to keep shrinking until smallest possible
                min_length = min(min_length, r - l + 1);
                // now shrinking the window from the left
                sum -= nums[l];
                l++;
            }
        }
        if(min_length == INT_MAX){
            return 0;
        } else {
            return min_length;
        }
    }
};