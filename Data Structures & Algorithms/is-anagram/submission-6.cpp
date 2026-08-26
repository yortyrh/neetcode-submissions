class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        array<int, 26> a{}, b{};
        for (int i = 0; i != s.length(); ++i) {
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        return a == b;
    }
};
