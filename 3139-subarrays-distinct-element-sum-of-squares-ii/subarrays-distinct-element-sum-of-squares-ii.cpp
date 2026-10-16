class Solution {
    static const int MOD = 1e9 + 7;

    vector<long long> sum, sq, lazy;
    int n;

    // Apply an addition to a whole segment
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // (x + val)^2 = x^2 + 2*x*val + val^2
        sq[node] = (sq[node] + 2 * val * sum[node]
                    + len * val % MOD * val) % MOD;

        sum[node] = (sum[node] + len * val) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    // Pass pending updates to children
    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    // Add val to every element in range [ql, qr]
    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            // Update subarrays that gain a new distinct element
            int left = last[nums[i]] + 1;

            update(1, 0, n - 1, left, i, 1);

            last[nums[i]] = i;

            // Add squared counts of all subarrays ending at i
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};