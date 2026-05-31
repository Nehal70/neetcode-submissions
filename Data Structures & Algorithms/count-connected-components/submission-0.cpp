class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //build the graph
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        int count = 0;
        int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        //run dfs on the graph
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                //i is visited
                dfs(graph, visited, count, i);
                ans += 1;
            }
            if (count == n) {
                return ans;
            }
        }
        return ans;
    }

    void dfs (vector<vector<int>>& graph, vector<bool>& visited, int& count, int node) {
        visited[node] = true;
        count += 1;
        for (int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                //dfs if not visited yet
                dfs(graph, visited, count, graph[node][i]);
            }
        }
    }
};
