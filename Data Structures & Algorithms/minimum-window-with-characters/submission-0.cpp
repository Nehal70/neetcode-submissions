class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> targetCount;
        for (char c : t) targetCount[c]++;

        unordered_map<char, int> windowCount;
        int have = 0;
        int need = targetCount.size(); // Number of unique characters to satisfy
        
        int resLen = INT_MAX;
        int resStart = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            windowCount[c]++;

            // If we just reached the required frequency for this character
            if (targetCount.count(c) && windowCount[c] == targetCount[c]) {
                have++;
            }

            // While window is valid, try to shrink it
            while (have == need) {
                // Update our smallest window result
                if ((right - left + 1) < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }

                // Pop from the left
                char leftChar = s[left];
                windowCount[leftChar]--;
                
                // If removing this char breaks the "have" requirement
                if (targetCount.count(leftChar) && windowCount[leftChar] < targetCount[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return (resLen == INT_MAX) ? "" : s.substr(resStart, resLen);
    }
};