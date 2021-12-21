class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        std::vector<int> idxs;
        
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (seen.find(diff) != seen.end()) {
                idxs.push_back(i);
                idxs.push_back(seen[diff]);
                return idxs;
            }
            
            seen[nums[i]] = i;
        }
        return idxs;
    }
};
