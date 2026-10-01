class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Create a stack
        for (char c : s) {
            // If opening bracket, push it
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            // If closing bracket
            else {
                // If stack is empty, no bracket to match
                if (st.empty())
                    return false;

                // Get the top bracket
                char top = st.top();
                st.pop();

                // Check if brackets match
                if (c == ')' && top != '(')
                    return false;

                if (c == ']' && top != '[')
                    return false;

                if (c == '}' && top != '{')
                    return false;
            }
        }
        // Stack should be empty for valid brackets
        return st.empty();
    }
};