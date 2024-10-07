class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";  // To store the final result
        int openCount = 0;   // This will track the depth of nested parentheses

        for (char c : s) {
            if (c == '(') {
                // Only add the '(' if it's not an outermost parenthesis
                if (openCount > 0) {
                    result += c;
                }
                openCount++;
            } else if (c == ')') {
                openCount--;
                // Only add the ')' if it's not an outermost parenthesis
                if (openCount > 0) {
                    result += c;
                }
            }
        }
        return result;
    }
};
