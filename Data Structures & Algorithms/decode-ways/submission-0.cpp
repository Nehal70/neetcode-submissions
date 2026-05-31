class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways(s.size());
        for (int i = 0; i < s.size(); i++) {
    if (i == 0) {
        if (s[i] == '0') return 0; // Fixed = to ==
        ways[i] = 1;
    } else {
        int curr = s[i] - '0';
        int prev = s[i-1] - '0';
        int combined = prev * 10 + curr;

        // If current is '0', it MUST combine with the previous
        if (curr == 0) {
            if (prev == 1 || prev == 2) {
                ways[i] = (i >= 2) ? ways[i-2] : 1; 
            } else {
                return 0; // "30", "00", etc. are invalid
            }
        } 
        // If current is not '0', check if it CAN combine with previous
        else {
            ways[i] = ways[i-1]; // Start with ways to decode it as a single digit
            if (combined >= 10 && combined <= 26) {
                ways[i] += (i >= 2) ? ways[i-2] : 1;
            }
        }
    }
}
        return ways[s.size() - 1];
    }
};
