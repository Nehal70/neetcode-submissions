class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<bool> visited(n, false);
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> bfsQueue; 
        //create graph
        for (int i = 0; i < times.size(); i++) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        dist[k] = 0;
        bfsQueue.push({dist[k], k});
        while (bfsQueue.size()) {
            pair<int, int> minDist = bfsQueue.top(); bfsQueue.pop();
            visited[minDist.second] = true;
            for(int i = 0; i < graph[minDist.second].size(); i++) {
                pair<int, int> nextNode = graph[minDist.second][i];
                if (nextNode.second + minDist.first < dist[nextNode.first]) {
                    dist[nextNode.first] = nextNode.second + minDist.first;
                    bfsQueue.push({dist[nextNode.first], nextNode.first});
                }
            }
        }
        //check if return should be -1
        int max = 0;
        for (int i = 1; i <= n; i++) {
            int distance = dist[i];
            if (distance == INT_MAX) {
                return -1;
            } else {
                if (distance > max) {
                    max = distance;
                }
            }
        }
        return max;
    }   
};
