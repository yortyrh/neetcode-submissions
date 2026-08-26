class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return size(s) != size(nums);
    }
};