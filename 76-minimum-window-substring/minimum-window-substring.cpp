class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        unordered_map<char, int> window;
        int required = need.size();  // number of unique chars in t we need to fully satisfy
        int formed = 0;               // number of unique chars currently satisfied

        int left = 0;
        int bestLen = INT_MAX, bestStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // try to shrink the window from the left while it's still valid
            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};