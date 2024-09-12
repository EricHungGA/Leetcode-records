class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // 1. keep track of psum of even nums only in a vector
        // 2. when we change a num, first check if old num is even
        // if yes, subtract num from psum
        // 3. find new resultant num, check if it is even
        // if yes, add to psum
        // 4. remember for each query to add the psum val into result vector
        vector<int>result;
        int pSumEven = 0;
        // initializing psum
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] % 2 == 0){
                pSumEven += nums[i];
            }
        }
        for(int i = 0; i < queries.size(); i++){
            // queries[i][0] = value to add
            // queries[i][1] = position to add it at in nums
            int addVal = queries[i][0];
            int pos = queries[i][1];
            // check if num being changed is even
            if(nums[pos] % 2 == 0){
                pSumEven -= nums[pos];
            }
            // now change value in nums
            nums[pos] += addVal;
            // check if new value is even
            if(nums[pos] %2 == 0){
                pSumEven += nums[pos];
            }
            // now add the current pSumEven val to vector
            result.push_back(pSumEven);
        }
        return result;
    }
};