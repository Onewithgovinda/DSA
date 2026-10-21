
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Check if already sorted
        if (is_sorted(s.begin(), s.end()))
            return 0;

        // Cannot sort a reversed string of length 2
        if (n == 2)
            return -1;

        // Find minimum and maximum characters
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // One operation is enough
        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        // Check the middle characters
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        // Otherwise, three operations are needed
        return 3;
    }
};
