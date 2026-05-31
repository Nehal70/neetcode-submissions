class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0 || s[0] == ')' || s[0] == ']' || s[0] == '}' ) {
            return false;
        }
        vector<char> char_stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                char_stack.push_back(s[i]);
            } else if (s[i] == ')') {
                if (char_stack.back() == '(') {
                    char_stack.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (char_stack.back() == '[') {
                    char_stack.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (char_stack.back() == '{') {
                    char_stack.pop_back();
                } else {
                    return false;
                }
            }
        }
        return !char_stack.size();
    }
};
