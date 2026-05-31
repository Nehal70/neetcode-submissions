class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> duplicateSet;
        for(int i = 0; i < nums.size(); i++) {
            if(duplicateSet.count(nums[i])) {
                //number was already in set
                return nums[i];
            } else {
                duplicateSet.insert(nums[i]);
            }
        }
        return -1;
    }
};
