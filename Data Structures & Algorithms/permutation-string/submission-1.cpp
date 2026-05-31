class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //create vector s1
        vector<int> freqMap(26);
        for (int i = 0; i < s1.size(); i++) {
            freqMap[s1[i] - 'a'] += 1;
        }
        //create frequency map for windows iteratively
        vector<int> windowFreqMap(26);
        for (int i = 0; i < s2.size(); i++) {
            if (i < s1.size()) {
                windowFreqMap[s2[i] - 'a'] += 1;
            } else {
                windowFreqMap[s2[i] - 'a'] += 1;
                windowFreqMap[s2[i - s1.size()] - 'a'] -= 1;
            }
            if (windowFreqMap == freqMap) {
                return true;
            }
        }
        if (windowFreqMap == freqMap) {
            return true;
        }
        return false;
        
    }
};
