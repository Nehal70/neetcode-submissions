#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree with n nodes MUST have exactly n-1 edges
        if (edges.size() != n - 1) return false;
        if (n == 0) return false; // Or true depending on problem constraints for empty tree

        // Step 1: Build the Adjacency List
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: DFS to check connectivity
        vector<bool> visited(n, false);
        dfs(visited, adj, 0);

        // Step 3: Check if all nodes were reached
        return find(visited.begin(), visited.end(), false) == visited.end();
    }

    void dfs(vector<bool>& visited, vector<vector<int>>& adj, int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(visited, adj, neighbor);
            }
        } 
    }
};