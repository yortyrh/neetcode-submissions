bool has_edge(const string& a, const string& b) {
    int n = a.length();
    int diff = 0;
    for (int i = 0; i != n; ++i) {
        if (a[i] != b[i]) {
            ++diff;
        }
        if (diff > 1) {
            return false;
        }
    }
    return diff == 1;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (endWord == beginWord) {
            //cout << "Ending: endWord == beginWord" << '\n';
            return 0;
        }
        int n = wordList.size();
        int source = 0;
        int target = -1;
        vector<vector<int>> g(n+1);
        for (int i = 0; i < n; ++i) {
            auto w = wordList[i];
            if (w == endWord) {
                target = i+1;
            }
            if (has_edge(beginWord, w)) {
                g[0].emplace_back(i+1);
                g[i+1].emplace_back(0);
            }
        }
        if (target == -1) {
            //cout << "Ending: target == -1" << '\n';
            return 0;
        }
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (has_edge(wordList[i], wordList[j])) {
                    g[i+1].emplace_back(j+1);
                    g[j+1].emplace_back(i+1);
                }
            }
        }
        queue<pair<int,int>> q;
        vector<bool> visited(n+1, false);
        visited[source] = true;
        q.emplace(source, 1);
        while(!empty(q)) {
            auto& [i, step] = q.front(); q.pop();
            for (auto j : g[i]) {
                if (j == target) return step+1; 
                if (!visited[j]) {
                    visited[j] = true;
                    q.emplace(j, step+1);
                }
            }
        }
        //cout << "Ending: final" << '\n';
        return 0;
    }
};
