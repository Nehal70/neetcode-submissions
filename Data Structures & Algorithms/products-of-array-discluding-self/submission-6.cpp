class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //left products
        vector<int> leftProducts;
        leftProducts.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            leftProducts.push_back(nums[i - 1] * leftProducts.back());
        }
        //right products
        vector<int> rightProducts(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) { 
                rightProducts[i] = 1;
            } else {
                rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
            }
        }

        //compute result vector
        vector<int> results(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            results[i] = (leftProducts[i] * rightProducts[i]);
        }

        return results;
    }
};
