class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;
        for (char c : s) {
            // Opening bracket
            if (c == '(') {
                minOpen++;
                maxOpen++;
            }
            // Closing bracket
            else if (c == ')') {
                minOpen--;
                maxOpen--;
            }
            // '*' can be (, ) or empty
            else {
                minOpen--;  // '*' acts as ')'
                maxOpen++;  // '*' acts as '('
            }
            // Too many closing brackets
            if (maxOpen < 0)
                return false;

            // Minimum cannot be negative
            if (minOpen < 0)
                minOpen = 0;
        }
        // If we can have 0 open brackets, it is valid
        return minOpen == 0;
    }
};