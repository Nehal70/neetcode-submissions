class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<vector<int>> result;
        for (int i = 0; i < sorted.size() - 1; i++) {
            if (i > 0 && sorted[i] == sorted[i - 1]) {
                continue;
            }
            int start = i + 1;
            int end = sorted.size() - 1;
            while (start < end) {
                if (sorted[start] + sorted[end] + sorted[i] == 0) {
                    result.push_back({sorted[start], sorted[end], sorted[i]});
                    while (start < end && sorted[start] == sorted[start+1]) {
                        start++;
                    } 
                    while (start < end && sorted[end] == sorted[end-1]) {
                        end--;
                    } 
                    start++;
                    end--;
                } else if (sorted[start] + sorted[end] + sorted[i] < 0) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return result;
    } 
};
