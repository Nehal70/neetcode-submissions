class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n + 1);
        for (int i = 1; i <= n; i++) {
            uint32_t num = (uint32_t) i;
            int index = num & (num - 1);
            count[i] = count[index] + 1;
        }
        return count;
    }
};
