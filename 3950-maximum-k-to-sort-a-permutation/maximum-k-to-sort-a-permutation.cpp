class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        // Check elements that are not in the correct position
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i]) {
                ans &= nums[i];
            }
        }
        // Return 0 if the array is already sorted
        return max(ans, 0);
    }
};