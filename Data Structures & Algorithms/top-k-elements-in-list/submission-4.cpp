class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        priority_queue<pair<int, int>> maxHeap;
        //Build freqMap
        for (int i = 0 ; i < nums.size(); i++) {
            //Update FreqMap;
            freqMap[nums[i]]++;
        }
        //Build MaxHeap
        for (auto const& [key, value] : freqMap) {
            maxHeap.push({value, key});
        }
        //pop
        vector<int> result;
        for (int i = 0 ; i < k; i++) {
            pair<int, int> newpair = maxHeap.top(); maxHeap.pop();
            result.push_back(newpair.second);
        }
        return result;
    }
};
