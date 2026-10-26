
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        // Check every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Start a new island
                if (grid[i][j] == 0)
                    continue;

                long long sum = 0;
                stack<pair<int, int>> st;

                st.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;  // Mark visited

                // Explore the island
                while (!st.empty()) {
                    auto [r, c] = st.top();
                    st.pop();

                    int dr[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};

                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        // Check boundaries and land
                        if (nr >= 0 && nr < m &&
                            nc >= 0 && nc < n &&
                            grid[nr][nc] > 0) {

                            sum += grid[nr][nc];
                            grid[nr][nc] = 0;
                            st.push({nr, nc});
                        }
                    }
                }

                // Check if island sum is divisible by k
                if (sum % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};
