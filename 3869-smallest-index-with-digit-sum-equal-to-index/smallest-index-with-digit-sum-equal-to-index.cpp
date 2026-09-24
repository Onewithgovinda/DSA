class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        // Check every index one by one
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int sum = 0;
            // Calculate the sum of digits of nums[i]
            // Example: 123 -> 1 + 2 + 3 = 6
            while (n > 0) {
                sum += n % 10;  // Get last digit
                n /= 10;        // Remove last digit
            }
            // If digit sum is equal to the current index,
            // we found the smallest valid index
            if (sum == i) {
                return i;
            }
        }
        // No index satisfies the condition
        return -1;
    }
};