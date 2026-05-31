class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        
        for (const string& s : tokens) {
            // Check if it's an operator by looking at the string length and first char
            if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) {
                // Popping order matters: 1st pop is Right, 2nd pop is Left
                int r = stack.back(); stack.pop_back();
                int l = stack.back(); stack.pop_back();
                
                if (s[0] == '+') stack.push_back(l + r);
                else if (s[0] == '-') stack.push_back(l - r);
                else if (s[0] == '*') stack.push_back(l * r);
                else if (s[0] == '/') stack.push_back(l / r);
            } else {
                // It's a number (could be negative, e.g., "-11")
                stack.push_back(stoi(s));
            }
        }
        return stack.back();
    }
};