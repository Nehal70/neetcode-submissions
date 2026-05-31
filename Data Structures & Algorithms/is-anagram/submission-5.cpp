class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;
        for (int i = 0; i < s.size(); i++) {
            s_freq[s[i]]++;
            t_freq[t[i]]++;
        }
        if (s_freq == t_freq) {
            return true;
        } else {
            return false;
        }
    }
};
