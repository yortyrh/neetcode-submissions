class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mapp.contains(target-nums[i])) {
                return {mapp[target-nums[i]], i};
            }
            mapp[nums[i]] = i;
        }
    }
};
