class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        // First, calculate the sum of all elements
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }
        // This will store the sum of elements on the left side
        int leftSum = 0;
        // Check every index one by one
        for (int i = 0; i < nums.size(); i++) {
            // Total sum contains:
            // leftSum + current element + rightSum
            // So, rightSum = totalSum - leftSum - current element
            int rightSum = totalSum - leftSum - nums[i];

            // If both sides are equal,
            // we found the pivot index
            if (leftSum == rightSum) {
                return i;
            }
            // Add the current element to leftSum
            // before moving to the next index
            leftSum += nums[i];
        }
         // If no pivot index is found
        return -1;
    }
};