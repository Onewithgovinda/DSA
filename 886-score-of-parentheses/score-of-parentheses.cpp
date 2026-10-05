class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);  // Starting score
        for (char c : s) {
            // Opening bracket
            if (c == '(') {
                st.push(0);
            }
            // Closing bracket
            else {
                int x = st.top();
                st.pop();
                // () = 1
                if (x == 0) {
                    st.top() += 1;
                }
                // (A) = 2 * A
                else {
                    st.top() += 2 * x;
                }
            }
        }

        return st.top();
    }
};