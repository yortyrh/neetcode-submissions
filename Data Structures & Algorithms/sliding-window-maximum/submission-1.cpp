class SparseTable {
private:
    int n;
    int max_log;
    // table[i][j] stocke le max pour la plage débutant à i et de longueur 2^j
    std::vector<std::vector<int>> table;
    // Table de précalcul des logarithmes pour optimiser les requêtes en O(1)
    std::vector<int> log_table;

    void build(const std::vector<int>& arr) {
        // Remplir la première colonne avec les éléments du tableau
        for (int i = 0; i < n; ++i) {
            table[i][0] = arr[i];
        }

        // Remplir le reste de la table dynamique
        for (int j = 1; j <= max_log; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = std::max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    void precomputeLogs() {
        log_table[1] = 0;
        for (int i = 2; i <= n; ++i) {
            log_table[i] = log_table[i / 2] + 1;
        }
    }

public:
    SparseTable(const std::vector<int>& arr) {
        n = arr.size();
        if (n == 0) return;

        max_log = std::log2(n);
        table.assign(n, std::vector<int>(max_log + 1, 0));
        log_table.assign(n + 1, 0);

        precomputeLogs();
        build(arr);
    }

    // Requête en O(1) pour obtenir le max dans la plage inclusive [L, R]
    int query(int L, int R) {
        if (L > R || L < 0 || R >= n) {
            throw std::out_of_range("Indices de requête invalides");
        }
        
        int length = R - L + 1;
        int k = log_table[length]; // Plus grande puissance de 2 qui entre dans la plage
        
        // Le max de la plage est le max entre les deux blocs chevauchants de taille 2^k
        return std::max(table[L][k], table[R - (1 << k) + 1][k]);
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums);
        vector<int> ans(n-k+1);
        for (int i = 0; i <= n-k; ++i) {
            ans[i] = st.query(i, i+k-1);
        }

        return ans;
    }
};
