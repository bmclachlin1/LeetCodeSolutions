class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> numBits(num+1);
        for (int i = 0; i <= num; i++) {
            int num = i;
            while (num) {
                if (num % 2 == 1) {
                    numBits[i]++;
                }
                num /= 2;
            }
        }
        
        return numBits;
    }
};