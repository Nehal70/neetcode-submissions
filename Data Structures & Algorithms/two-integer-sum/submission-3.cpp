class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); i++) {
            //
            if (lookup.count(nums[i])) {
                return {lookup[nums[i]], i};
            } else {
                //pair doesn't exist yet
                lookup[target - nums[i]] = i;
            }
        }
        return {};
    }
};
