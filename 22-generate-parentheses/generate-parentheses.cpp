class Solution {
public:
    vector<string> ans;
    void solve(string s, int open, int close, int n) {
        // If string has n pairs, add it to answer
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }
        // Add opening bracket if available
        if (open < n) {
            solve(s + "(", open + 1, close, n);
        }
        // Add closing bracket only if it has a matching opening bracket
        if (close < open) {
            solve(s + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};