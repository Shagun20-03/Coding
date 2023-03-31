class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        // int n=string.size();
        // int m=string[0].size();
        // int dp[m][n];
        // dp[0][0]=0;
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         dp[i][0]=0;
        //         dp[0][j]=0;
        //     }
        // }
         int rows = pizza.size(), cols = pizza[0].size();
        vector apples(rows + 1, vector<int>(cols + 1));
        vector dp(k, vector(rows, vector<int>(cols)));
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                apples[row][col] = (pizza[row][col] == 'A') + apples[row + 1][col] +
                                   apples[row][col + 1] - apples[row + 1][col + 1];
                dp[0][row][col] = apples[row][col] > 0;
            }
        }
        const int mod = 1000000007;
        for (int remain = 1; remain < k; remain++) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    for (int next_row = row + 1; next_row < rows; next_row++) {
                        if (apples[row][col] - apples[next_row][col] > 0) {
                            (dp[remain][row][col] += dp[remain - 1][next_row][col]) %= mod;
                            }
                    }
                    for (int next_col = col + 1; next_col < cols; next_col++) {
                        if (apples[row][col] - apples[row][next_col] > 0) {
                            (dp[remain][row][col] += dp[remain - 1][row][next_col]) %= mod;
                        }
                    }
                }
            }
        }
        return dp[k - 1][0][0];
    }
};