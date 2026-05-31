class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int maxWater = 0;
        while (start < end) {
            int volume = 0;
            if (heights[start] < heights[end]) {
                //end is max
                volume = heights[start] * (end - start);
                start++;
            } else {
                //start is max
                volume = heights[end] * (end - start);
                end--;
            }
            //check if should set up maxWater
            maxWater = (volume > maxWater) ? (volume) : maxWater;
        }
        return maxWater;
    }
};
