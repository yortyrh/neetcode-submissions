class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> window;
        vector<int> ans;
        ans.reserve(n-k+1);
        for (int i = 0; i < k-1; ++i) {
            while(!window.empty() && nums[window.back()] <= nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
        }

        for (int i = k-1; i < n; ++i) {
            while(!window.empty() && window.front() < i-k+1) {
                window.pop_front();
            }
            while(!window.empty() && nums[window.back()] <= nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
            ans.push_back(nums[window.front()]);
        }

        return ans;
    }
};
