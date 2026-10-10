class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        vector<int> diff;
        long long sum = 0;
        int n = nums1.size();

        // Calculate absolute differences
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            sum += d;
        }

        long long k = (long long)k1 + k2;

        // All differences can become zero
        if (sum <= k)
            return 0;

        // Binary search for the minimum maximum difference
        int left = 0, right = 100000;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            // Operations needed to make all differences <= mid
            for (int d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int limit = left;
        long long ans = 0;

        // Reduce every difference to the limit
        for (int d : diff) {
            int x = min(d, limit);
            ans += 1LL * x * x;
            k -= d - x;
        }

        // Use remaining operations to reduce differences at the limit
        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] >= limit && limit > 0) {
                ans -= 1LL * limit * limit;
                ans += 1LL * (limit - 1) * (limit - 1);
                k--;
            }
        }

        return ans;
    }
};