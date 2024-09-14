class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int open = 0; // To track the number of open parentheses

        for (char c : s) {
            if (c == '(') {
                if (open > 0) {
                    result += c; // Add '(' only if it's not the outermost
                }
                open++; // Increment open parentheses count
            } else {
                open--; // Decrement open parentheses count
                if (open > 0) {
                    result += c; // Add ')' only if it's not the outermost
                }
            }
        }

        return result;
    }
};