class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> curr;
        curr.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int currSize = curr.size();
            while (count < currSize) {
                vector<int> currVec = curr[count]; // access current vector
                currVec.push_back(nums[i]); //append current num to current vector
                curr.push_back(currVec); //push back new vector onto result curr list
                count++;
            }    
        }
        return curr;
    }
};
