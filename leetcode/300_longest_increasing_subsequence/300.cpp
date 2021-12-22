class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // See https://www.youtube.com/watch?v=CE2b_-XfVDk

        int dp[nums.size()];
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((nums[j] < nums[i]) && (dp[j] + 1 > dp[i])) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        int max_subseq_len = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] > max_subseq_len) {
                max_subseq_len = dp[i];
            }
        }
        
        return max_subseq_len;
    }
};
