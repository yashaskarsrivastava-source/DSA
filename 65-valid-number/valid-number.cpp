class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        
        // 1. Optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
        
        bool digitsSeenBeforeDot = false;
        bool dotSeen = false;
        bool digitsSeenAfterDot = false;
        
        // 2. Digits and optional dot (integer or decimal part)
        while (i < n && isdigit(s[i])) {
            digitsSeenBeforeDot = true;
            i++;
        }
        
        if (i < n && s[i] == '.') {
            dotSeen = true;
            i++;
            while (i < n && isdigit(s[i])) {
                digitsSeenAfterDot = true;
                i++;
            }
        }
        
        // Must have at least one digit before or after the dot
        if (!digitsSeenBeforeDot && !digitsSeenAfterDot) {
            return false;
        }
        
        // 3. Optional exponent
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            
            // sign after e
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                i++;
            }
            
            bool digitsInExponent = false;
            while (i < n && isdigit(s[i])) {
                digitsInExponent = true;
                i++;
            }
            
            if (!digitsInExponent) {
                return false;
            }
        }
        
        // Must have consumed the entire string
        return i == n;
    }
};