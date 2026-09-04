
class Solution {
public:
    vector<string> makeSolution(const vector<int>& solution) {
        int n = solution.size();
        vector<string> ans(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            ans[i][solution[i]] = 'Q';
        }
        return ans;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> solution;
        vector<int> rows(n, 0);
        vector<int> diagPlus(n << 1, 0);
        vector<int> diagMinus(n << 1, 0);
        auto backtrack = [&](auto& self, int j)->void {
            if (j == n) {
                ans.push_back(makeSolution(solution));
            }
            for(int i = 0; i < n; ++i) {
                if (!rows[i] && !diagPlus[i+j] && !diagMinus[i-j+n]) {
                    solution.push_back(i);
                    rows[i] = 1;
                    diagPlus[i+j] = 1;
                    diagMinus[i-j+n] = 1;
                    self(self, j+1);
                    rows[i] = 0;
                    diagPlus[i+j] = 0;
                    diagMinus[i-j+n] = 0;
                    solution.pop_back();
                }
            }
        };
        backtrack(backtrack, 0);
        return ans;
    };
};
