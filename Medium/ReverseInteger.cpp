class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        while (x != 0) {
            long long last = x % 10;
            x /= 10;
            reversed = reversed * 10 + last;
        }
        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }
        return reversed;
    }
};