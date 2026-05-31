class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> minHeap;
        //MinHeap built
        for (vector<int> point: points) {
            long distance = long(point[0] * point[0]) + long(point[1] * point[1]); //Euclidian Distance
            minHeap.push({distance, point});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        } 
        //result vector from minHeap
        vector<vector<int>> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = minHeap.top().second; minHeap.pop();
        }
        return result;
    }
};
