class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::vector<int> digits;
        
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        
        for (int i = 0; i < digits.size() / 2; ++i) {
            if (digits[i] != digits[digits.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
