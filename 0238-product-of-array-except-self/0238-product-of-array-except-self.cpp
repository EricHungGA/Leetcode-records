class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 1. calculate running product for all elements to left of i
        // 2. multiply these values from the right starting with 1 (for rightmost val)
        // 3. store the values in solution vector
        vector<int> solution(nums.size(),1);
        int running_product = 1;
        for(int i = 0; i < nums.size(); i++){
            solution[i] *= running_product;
            running_product *= nums[i];
        }
        
        int right_product = 1;
        for(int i = nums.size() - 1; i >=0; i--){
            solution[i] *= right_product;
            right_product *= nums[i];
        }
        return solution;
    }
};