class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int L = 0;
        int R = n-1;
        while (L < R) {
            while (L < R && !isalnum(s[L])) ++L;
            while (L < R && !isalnum(s[R])) --R;
            if (L >= R) break;
            if (tolower(s[L]) != tolower(s[R])) return false;
            ++L;
            --R;
        }
        return true;
    }
};
