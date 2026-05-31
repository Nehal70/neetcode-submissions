class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> lastSeen;
        int maxLength = 1;
        lastSeen[s[0]] = 0;
        int i = 1;
        int runningLength = 1;
        int left = 0;
        while (i < s.size()) {
            if (lastSeen.count(s[i]) && lastSeen[s[i]] >= left) {
                //this has been seen before
                //update maxLength if required
                if (runningLength > maxLength) {
                    maxLength = runningLength;
                }
                //update left
                left = lastSeen[s[i]] + 1;
                //update runningLength
                runningLength = i - left + 1;
                //update last seen index
                lastSeen[s[i]] = i; 
                //go to next letter
                
            } else {
                lastSeen[s[i]] = i; 
                //if this hasn't been seen before
                runningLength += 1;
                
            }
            i += 1;
        }
        
        return (runningLength > maxLength) ? (runningLength) : maxLength;
    }
};
