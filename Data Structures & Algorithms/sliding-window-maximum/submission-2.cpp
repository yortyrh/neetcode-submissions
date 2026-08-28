class SparseTable {
private:
    int n;
    int max_log;
    std::vector<std::vector<int>> table;

    void build(const std::vector<int>& arr) {
        // Remplir la première colonne avec les éléments du tableau
        for (int i = 0; i < n; ++i) {
            table[i][0] = arr[i];
        }

        // Remplir le reste de la table dynamique
        for (int j = 1; j <= max_log; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

public:
    SparseTable(const std::vector<int>& arr, int k) {
        n = arr.size();
        if (n == 0) return;

        max_log = __lg(k);
        table.assign(n, std::vector<int>(max_log + 1, 0));
        build(arr);
    }

    // Requête en O(1) pour obtenir le max dans la plage inclusive [L, R]
    int query(int i, int size) {
        if (size == 1) {
            return table[i][0];
        }
        int first_log = __lg(size);
        int first_one = 1<<first_log;
        int left = size - first_one;
        return left ? max(table[i][first_log], query(i+first_one, left)) : table[i][first_log];
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums, k);
        vector<int> ans(n-k+1);
        for (int i = 0; i <= n-k; ++i) {
            ans[i] = st.query(i, k);
        }

        return ans;
    }
};
