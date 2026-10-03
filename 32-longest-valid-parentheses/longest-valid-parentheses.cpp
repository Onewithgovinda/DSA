class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        // Base index
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            // Opening bracket → push index
            if (s[i] == '(') {
                st.push(i);
            }
            // Closing bracket
            else {
                st.pop();
                // No matching opening bracket
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    // Calculate valid length
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};