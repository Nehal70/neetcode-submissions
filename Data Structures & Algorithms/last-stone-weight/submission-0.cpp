class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        //BUILD THE HEAP
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        while (maxHeap.size() > 1) {
            int competitor1 = maxHeap.top(); maxHeap.pop();
            int competitor2 = maxHeap.top(); maxHeap.pop();
            if (competitor1 > competitor2) {
                maxHeap.push(competitor1 - competitor2);
            } else if (competitor2 > competitor1) {
                maxHeap.push(competitor2 - competitor1);
            }
        }
        return (maxHeap.size() == 1) ? (maxHeap.top()) : (0);
    }
};
