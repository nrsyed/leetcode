class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum {nums[0]};
        int curr_sum {nums[0]};
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > curr_sum + nums[i]) {
                curr_sum = 0;
            }
            curr_sum += nums[i];
            
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
        }
        return max_sum;
    }
};
