class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> set;
        int max_len {0};
        
        int i = 0, j = 0;
        for (; j < s.size(); ++j) {
            if (set.count(s[j])) {
                max_len = max(max_len, j-i);
                while (s[i] != s[j] && i <= j) {
                    set.erase(s[i]);
                    i++;
                }
                i++;
            }
            set.insert(s[j]);
        }
        return max(max_len, j-i);
    }
};
