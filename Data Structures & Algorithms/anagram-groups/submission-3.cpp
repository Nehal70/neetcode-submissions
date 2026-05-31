class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            anagrams[key].push_back(strs[i]);
        }
        //loop through map
        vector<vector<string>> result;
        for (auto const& [key, val] : anagrams) {
            result.push_back(val);
        }
        return result;
    }
};
