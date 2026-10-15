class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Choose starting index
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            // Choose ending index
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);  // Add element to set

                int count = st.size();  // Count distinct elements
                ans += count * count;   // Add square
            }
        }

        return ans;
    }
};