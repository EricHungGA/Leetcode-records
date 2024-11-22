class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // First scenario: Rob houses 0 to n-2 (excluding last house)
        vector<int> dp1(n-1);  // Only need n-1 size for first scenario
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n-1; i++) {  // Only go up to n-2
            dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
        }
        
        // Second scenario: Rob houses 1 to n-1 (excluding first house)
        vector<int> dp2(n-1);  // Only need n-1 size for second scenario
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        
        for (int i = 2; i < n-1; i++) {  // Process houses 3 to n
            dp2[i] = max(dp2[i-2] + nums[i+1], dp2[i-1]);
        }
        
        return max(dp1.back(), dp2.back());
    }
};