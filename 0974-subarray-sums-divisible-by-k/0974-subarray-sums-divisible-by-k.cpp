class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        int remainder;
        int sum = 0;
        vector<int> mod_count(k,0);
        mod_count[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum+= nums[i];
            remainder = sum % k;
            int remainder = (sum % k + k) % k;
            result += mod_count[remainder];
            mod_count[remainder]++;
        }
     return result;   
    }
};