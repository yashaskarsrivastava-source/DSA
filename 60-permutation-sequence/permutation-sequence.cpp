class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);
        vector<char> digits;
        
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
            digits.push_back('0' + i);
        }
        
        k--; // convert to 0-indexed
        
        string result;
        for (int i = n; i >= 1; i--) {
            int idx = k / factorial[i - 1];
            k %= factorial[i - 1];
            result += digits[idx];
            digits.erase(digits.begin() + idx);
        }
        
        return result;
    }
};