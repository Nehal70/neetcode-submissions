class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count = 0;
        for (int i = 0 ; i <= 2*nums.size(); i++) {
            if (i < nums.size()) {
                count = count ^ nums[i];
            } else {
                count = count ^ (i - nums.size());
            }
        }
        return count;
    }
};
