
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][0]: Entered from above
        // dp[i][j][1]: Entered from left

        vector<vector<array<long long, 2>>> dp(
            m, vector<array<long long, 2>>(n, {0, 0})
        );

        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Movement from above
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        dp[i][j][0] =
                            (dp[i - 1][j][0] +
                             dp[i - 1][j][1]) % MOD;
                    }
                    else {
                        dp[i][j][0] = dp[i - 1][j][1];
                    }
                }

                // Movement from left
                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        dp[i][j][1] =
                            (dp[i][j - 1][0] +
                             dp[i][j - 1][1]) % MOD;
                    }
                    else {
                        dp[i][j][1] = dp[i][j - 1][0];
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
};
