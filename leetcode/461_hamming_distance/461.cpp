class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        uint8_t hamming_dist {0};
        while (diff) {
            hamming_dist += diff & 1;
            diff = diff >> 1;
        }
        return hamming_dist;
    }
};
