class Solution {
public:
    // Standard Find with Path Compression
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]); // Path compression makes it O(1)
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1); // Nodes are 1-indexed
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            int rootU = find(parent, u);
            int rootV = find(parent, v);

            if (rootU == rootV) {
                // They are already connected; this edge creates the cycle!
                return edge;
            } else {
                // Union: point one root to the other
                parent[rootU] = rootV;
            }
        }
        return {};
    }
};