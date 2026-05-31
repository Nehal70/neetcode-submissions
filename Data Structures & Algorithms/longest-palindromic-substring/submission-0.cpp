class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int start = 0, end = 0;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Window centered on a single character (aba)
            int len1 = expandFromCenter(s, i, i);
            // Case 2: Window centered between two characters (abba)
            int len2 = expandFromCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > end - start) {
                // Update our global "best" window bounds
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    int expandFromCenter(string s, int left, int right) {
        // Expand the window as long as it's a palindrome
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome found
        return right - left - 1;
    }
};