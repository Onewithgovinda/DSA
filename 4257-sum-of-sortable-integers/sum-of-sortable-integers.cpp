class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> drop(n, 0);
        // Prefix maximum
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }
        // Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        // Count decreasing adjacent pairs
        for (int i = 1; i < n; i++) {
            drop[i] = drop[i - 1] + (nums[i - 1] > nums[i]);
        }
        int ans = 0;
        // Check every divisor of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool valid = true;
            // Check every block of length k
            for (int i = 0; i < n; i += k) {
                int descents = drop[i + k - 1] - drop[i];
                // Include the circular boundary
                if (nums[i + k - 1] > nums[i])
                    descents++;
                // Check whether the block can be rotated
                if (descents > 1) {
                    valid = false;
                    break;
                }
                // Check the boundary between blocks
                if (i > 0 && prefMax[i] > suffMin[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans += k;
        }
        return ans;
    }
};