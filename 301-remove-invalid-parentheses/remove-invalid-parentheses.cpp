class Solution {
public:

    // Check if string is valid
    bool isValid(string s) {

        int count = 0;

        for (char c : s) {

            if (c == '(')
                count++;

            else if (c == ')')
                count--;

            // Too many ')'
            if (count < 0)
                return false;
        }

        // All '(' must be matched
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            string current = q.front();
            q.pop();

            // If valid, this is minimum removal level
            if (isValid(current)) {
                ans.push_back(current);
                found = true;
            }

            // Don't remove more if valid strings are found
            if (found)
                continue;

            // Remove one bracket
            for (int i = 0; i < current.size(); i++) {

                if (current[i] != '(' && current[i] != ')')
                    continue;

                string next = current.substr(0, i)
                            + current.substr(i + 1);

                // Avoid duplicates
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};