class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint8_t hamming_weight {0};
        while (n) {
            hamming_weight += n & 1;
            n = n >> 1;
        }
        return (int)hamming_weight;
    }
};
