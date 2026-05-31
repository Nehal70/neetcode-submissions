class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        //create a count map
        for (int num : nums) {
            frequency[num] += 1;
        }
        //do build heap
        priority_queue<pair<int, int>> maxHeap;
        for (auto const& [key, value]: frequency) {
            //sort by size
            maxHeap.push({value, key});
        }

        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
