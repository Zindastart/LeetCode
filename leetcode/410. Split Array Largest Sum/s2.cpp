// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(NM)
class Solution {
    typedef long long LL;
public:
    int splitArray(vector<int>& A, int M) {
        int N = A.size();
        vector<vector<LL>> dp(M + 1, vector<LL>(N, INT_MAX));
        LL s = 0;
        for (int i = 0; i < N; ++i) dp[1][i] = (s += A[i]);
        for (int m = 2; m <= M; ++m) {
            for (int i = m - 1; i < N; ++i) {
                LL sum = 0;
                for (int j = i; j >= m - 1; --j) {
                    sum += A[j];
                    dp[m][i] = min(dp[m][i], max(dp[m - 1][j - 1], sum));
                }
            }
        }
        return dp[M][N - 1];
    }
};