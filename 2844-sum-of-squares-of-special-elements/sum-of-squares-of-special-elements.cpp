class Solution {
public:
    int sumOfSquares(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        // Check each position
        for (int i = 0; i < n; i++) {

            // If index (1-based) divides n
            if (n % (i + 1) == 0) {

                // Add square of the element
                ans += nums[i] * nums[i];
            }
        }

        return ans;
    }
};