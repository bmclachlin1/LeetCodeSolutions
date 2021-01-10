class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i+1);
            int len2 = expandAroundCenter(s, i, i);
            int lenMax = max(len1, len2);
            if (lenMax > end - start) {
                start = i - (lenMax - 1) / 2;
                end = i + lenMax / 2;
            }
        }
        
        return s.substr(start, end-start + 1);
    }

private:
    int expandAroundCenter(string s, int left, int right) {
        int l = left, r = right;
        // keep expanding while in bounds and s[left] == s[right]
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        // return (R-1) - (L+1) + 1 = R - 1 - L - 1 + 1 = R - L - 1
        // Need the + 1 because if R-1 = 6 and l+1 = 3 then 6-3 = 3 but range[3, 6] = 4 (3, 4, 5, 6)
        return r - l - 1;
    }
};