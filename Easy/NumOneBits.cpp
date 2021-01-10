class Solution {
public:
    int hammingWeight(uint32_t n) {
        int numBits = 0;
        while (n) {
            if (n % 2 == 1) numBits++;
            n /= 2;
        }
        return numBits;
    }
};