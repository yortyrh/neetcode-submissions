struct Trie {
    array<unique_ptr<Trie>, 26> children{};
    bool ending {false};
    string word;
    void insert(const string& p_word, const int start) {
        int n = p_word.length();
        if (start == n) {
            this->ending = true;
            this->word = p_word;
            return;
        }
        int i = p_word[start]-'a';
        if (!this->children[i]) {
            this->children[i] = make_unique<Trie>();
        }
        this->children[i]->insert(p_word, start+1);
    }
    void print_all() {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (this->children[ch-'a'] && this->children[ch-'a']->ending) {
                cout << this->children[ch-'a']->word << ", ending on: " << ch << '\n';
            }
            if (this->children[ch-'a']) {
                this->children[ch-'a']->print_all();
            }
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        auto root = make_unique<Trie>();
        for(const auto& word: words) {
            root->insert(word, 0);
        }
        //root->print_all();
        auto valid = [&visited, &n, &m](int i, int j)->bool {
            return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j];
        };
        unordered_set<string> ans;
        auto f = [&](auto& self, const unique_ptr<Trie>& s, int i, int j)->void {
            auto ch = board[i][j];
            if (s->children[ch-'a']) {
                //cout << "i=" << i << ",j=" << j << '\n';
                const unique_ptr<Trie>& next_s = s->children[ch-'a'];
                if (next_s->ending) {
                    ans.emplace(next_s->word);
                    //cout << "next_s->word=" << next_s->word << '\n';
                }
                
                visited[i][j] = true;
                if (valid(i+1, j)) {
                    self(self, next_s, i+1, j);
                }
                if (valid(i, j+1)) {
                    self(self, next_s, i, j+1);
                }
                if (valid(i-1, j)) {
                    self(self, next_s, i-1, j);
                }
                if (valid(i, j-1)) {
                    self(self, next_s, i, j-1);
                }
                visited[i][j] = false;
            }
        };
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f(f, root, i, j);
            }
        }
        return {begin(ans), end(ans)};
    }
};
