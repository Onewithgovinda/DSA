class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Values are at most 1023, so there are 1024 XOR states
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        // Starting cell
        dp[0][0][grid[0][0]] = true;

        // Check every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // Come from above
                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }

                // Come from the left
                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }
            }
        }

        // Find the minimum XOR at the destination
        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x])
                return x;
        }

        return 0;
    }
};