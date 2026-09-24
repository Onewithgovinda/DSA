class Solution {
    public int smallestIndex(int[] nums) {

        // Check every index
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            int sum = 0;
            // Calculate the sum of digits
            // Example: 123 -> 1 + 2 + 3 = 6
            while (n > 0) {
                sum += n % 10;  // Get the last digit
                n /= 10;        // Remove the last digit
            }
            // Check if digit sum is equal to the index
            if (sum == i) {
                return i;       // Return the first/smallest valid index
            }
        }
        // If no index satisfies the condition
        return -1;
    }
}