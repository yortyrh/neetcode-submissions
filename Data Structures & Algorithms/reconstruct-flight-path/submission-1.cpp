class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int q = tickets.size();
        vector<string> airports;
        unordered_map<string,int> airport_ids;
        airports.reserve(q);
        airports.emplace_back("JFK");
        for (const auto& ticket : tickets) {
            airports.emplace_back(ticket[1]);
        }
        std::sort(airports.begin(), airports.end());
        airports.erase(std::unique(airports.begin(), airports.end()), airports.end());
        int n = airports.size();
        for (int i = 0; i < n; ++i) {
            auto airport = airports[i];
            airport_ids[airport] = i;
        }

        // constructing graph
        unordered_map<int,multiset<int>> graph;
        for (const auto& ticket : tickets) {
            graph[airport_ids[ticket[0]]].emplace(airport_ids[ticket[1]]);
        }

        vector<int> tail;
        tail.reserve(q+1);
        auto dfs = [&](auto& self, int node)->void {
            while (!graph[node].empty()) {
                auto it = graph[node].begin();
                auto to_node = *it;
                graph[node].erase(it);
                self(self, to_node);
                
            }
            tail.emplace_back(node);
        };

        dfs(dfs, airport_ids["JFK"]);
        vector<string> ans;
        for (int i = tail.size()-1; i >= 0; --i) {
            ans.emplace_back(airports[tail[i]]);
        }
        ans.reserve(q+1);
        return ans;
    }
};
