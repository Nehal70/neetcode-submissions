class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> isInAnagram;
        //for s
        for (int i = 0; i < s.size(); i++) {
            if (isInAnagram.count(s[i])) {
                //key already there
                isInAnagram[s[i]] += 1;
            } else {
                isInAnagram[s[i]] = 1;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (isInAnagram.count(t[i])) {
                //key already there
                if (isInAnagram[t[i]] > 1) {
                    isInAnagram[t[i]] -= 1;
                } else {
                    isInAnagram.erase(t[i]);
                }
            } else {
                return false;
            }
        }
        if (isInAnagram.size()) {
            return false;
        } else {
            return true;
        }
    }
};
