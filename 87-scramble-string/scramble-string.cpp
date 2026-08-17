class Solution {
public:
    unordered_map<string, int> memo; // key: i1,i2,len -> 0 (false), 1 (true)
    string s1, s2;
    
    bool isScramble(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        return solve(0, 0, s1.size());
    }
    
    bool solve(int i1, int i2, int len) {
        string key = to_string(i1) + "," + to_string(i2) + "," + to_string(len);
        if (memo.count(key)) return memo[key];
        
        string sub1 = s1.substr(i1, len);
        string sub2 = s2.substr(i2, len);
        
        if (sub1 == sub2) {
            memo[key] = 1;
            return true;
        }
        
        // Quick pruning: character counts must match
        int count[26] = {0};
        for (int i = 0; i < len; i++) {
            count[s1[i1 + i] - 'a']++;
            count[s2[i2 + i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                memo[key] = 0;
                return false;
            }
        }
        
        // Try every split point
        for (int i = 1; i < len; i++) {
            // Case 1: no swap — s1[i1..i1+i) vs s2[i2..i2+i), s1[i1+i..) vs s2[i2+i..)
            if (solve(i1, i2, i) && solve(i1 + i, i2 + i, len - i)) {
                memo[key] = 1;
                return true;
            }
            // Case 2: swap — s1[i1..i1+i) vs s2[i2+len-i..i2+len), s1[i1+i..) vs s2[i2..i2+len-i)
            if (solve(i1, i2 + len - i, i) && solve(i1 + i, i2, len - i)) {
                memo[key] = 1;
                return true;
            }
        }
        
        memo[key] = 0;
        return false;
    }
};