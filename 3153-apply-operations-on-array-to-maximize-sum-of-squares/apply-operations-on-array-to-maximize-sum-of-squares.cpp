class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        long long MOD = 1000000007;
        vector<int> count(31, 0);

        // Count set bits in every number
        for (int num : nums) {
            for (int i = 0; i < 31; i++) {
                if (num & (1 << i)) {
                    count[i]++;
                }
            }
        }

        long long ans = 0;

        // Build k numbers with maximum possible bits
        for (int j = 0; j < k; j++) {
            long long num = 0;

            for (int i = 0; i < 31; i++) {
                if (count[i] > 0) {
                    num |= (1LL << i);
                    count[i]--;
                }
            }

            // Add square of the number
            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};