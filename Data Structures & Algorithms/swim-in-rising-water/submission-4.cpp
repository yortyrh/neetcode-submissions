class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int,int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int ans = grid[0][0];
        q.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;
        while(!q.empty()) {
            auto [h, i, j] = q.top(); q.pop();
            ans = max(ans, -h);
            // cout << "h=" << h << ", ans=" << ans << '\n';
            if (i == n-1 && j == n-1) {
                return ans;
            }
            if (i > 0 && !visited[i-1][j]) {
                if (i-1 == n-1 && j == n-1) {
                    return max(ans, grid[n-1][n-1]);
                }
                q.emplace(-grid[i-1][j], i-1, j);
                //cout << "adding h=" << grid[i-1][j] << '\n';
                visited[i-1][j] = true;
            }
            if (j > 0 && !visited[i][j-1]) {
                if (i == n-1 && j-1 == n-1) {
                    return max(ans, grid[n-1][n-1]);
                }
                q.emplace(-grid[i][j-1], i, j-1);
                //cout << "adding h=" << grid[i][j-1] << '\n';
                visited[i][j-1] = true;
            }
            if (i < n-1 && !visited[i+1][j]) {
                if (i+1 == n-1 && j == n-1) {
                    return max(ans, grid[n-1][n-1]);
                }
                q.emplace(-grid[i+1][j], i+1, j);
                //cout << "adding h=" << grid[i+1][j] << '\n';
                visited[i+1][j] = true;
            }
            if (j < n-1 && !visited[i][j+1]) {
                if (i == n-1 && j+1 == n-1) {
                    return max(ans, grid[n-1][n-1]);
                }
                q.emplace(-grid[i][j+1], i, j+1);
                //cout << "adding h=" << grid[i][j+1] << '\n';
                visited[i][j+1] = true;
            }
        }
        return ans;
    }
};
