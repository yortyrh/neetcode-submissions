class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> window;
        for (int i = 0; i < k; ++i) {
            window.emplace(-nums[i]);
        }
        vector<int> ans(n-k+1);
        ans[0] = -(*window.begin());
        for (int i = 1; i <= n-k; ++i) {
            window.erase(window.find(-nums[i-1]));
            window.emplace(-nums[i+k-1]);
            ans[i] = -(*window.begin());
        }

        return ans;
    }
};
