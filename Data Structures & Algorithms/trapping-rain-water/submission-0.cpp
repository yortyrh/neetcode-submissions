class Solution {
public:
    int trap(vector<int>& height) {
        int n = size(height);
        vector<int> right_max(n, 0);
        right_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0; --i) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        int ans = 0;
        int left_max = height[0];
        for (int i = 1; i < n-1; ++i) {
            ans += max(0, min(left_max, right_max[i+1])-height[i]);
            left_max = max(left_max, height[i]);
        }
        return ans;
    }
};
