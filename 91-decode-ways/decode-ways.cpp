class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // empty string: one way (base case)
        dp[1] = 1; // first character is non-zero (checked above)
        
        for (int i = 2; i <= n; i++) {
            // Single digit: s[i-1] must be '1'-'9'
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            // Two digits: s[i-2..i) must form "10"-"26"
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};