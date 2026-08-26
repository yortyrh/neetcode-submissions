class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> a{}, b{};
        for (auto ch : s) {
            a[ch-'a']++;
        }
        for (auto ch : t) {
            b[ch-'a']++;
        }
        return a == b;
    }
};
