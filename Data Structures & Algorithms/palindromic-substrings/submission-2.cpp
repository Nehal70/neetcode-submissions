class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> pallindromeGrid(s.size(), vector<bool>(s.size(), false));
        int count = 0;
        for (int i = pallindromeGrid.size() - 1; i >= 0; i--) {
            for (int j = i; j < pallindromeGrid[0].size(); j++) {
                if (i == j) {
                    pallindromeGrid[i][j] = true;
                    count += 1;
                } else if (j - i == 1) {
                    if (s[i] == s[j]) {
                        pallindromeGrid[i][j] = true;;
                        count += 1;
                    }
                } else {
                    if ((s[i] == s[j]) && (pallindromeGrid[i + 1][j - 1])) {
                        pallindromeGrid[i][j] = true;
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
};
