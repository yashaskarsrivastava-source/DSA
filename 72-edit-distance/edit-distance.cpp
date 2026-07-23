class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases: converting empty string to the other
        for (int i = 0; i <= m; i++) dp[i][0] = i;   // delete all i chars
        for (int j = 0; j <= n; j++) dp[0][j] = j;   // insert all j chars

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // characters match, no operation needed
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // delete from word1
                        dp[i][j - 1],     // insert into word1
                        dp[i - 1][j - 1]  // replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};