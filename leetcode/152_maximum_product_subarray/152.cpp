class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod {nums[0]};
        int curr_max {1};
        int curr_min {1};
        
        for (int num : nums) {
            int _max {num * curr_max};
            int _min {num * curr_min};
            curr_max = max(num, max(_max, _min));
            curr_min = min(num, min(_max, _min));
            max_prod = max(curr_max, max_prod);
        }
        return max_prod;
    }
};
