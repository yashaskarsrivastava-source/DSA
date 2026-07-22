class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int idx = 0;
        
        while (idx < n) {
            // Step 1: Determine which words fit in current line
            int lineLen = words[idx].size();
            int last = idx + 1;
            
            while (last < n) {
                // +1 for the space that would separate words[last-1] and words[last]
                if (lineLen + 1 + words[last].size() > maxWidth) {
                    break;
                }
                lineLen += 1 + words[last].size();
                last++;
            }
            
            // words[idx..last-1] go on this line
            int numWords = last - idx;
            int numGaps = numWords - 1;
            
            string line = "";
            
            // Step 2: Check if this is the last line OR line has only 1 word
            if (last == n || numGaps == 0) {
                // Left justify: single space between words, pad right with spaces
                for (int i = idx; i < last; i++) {
                    line += words[i];
                    if (i != last - 1) {
                        line += " ";
                    }
                }
                while (line.size() < maxWidth) {
                    line += " ";
                }
            } else {
                // Fully justify: distribute spaces evenly
                int totalChars = 0;
                for (int i = idx; i < last; i++) {
                    totalChars += words[i].size();
                }
                int totalSpaces = maxWidth - totalChars;
                int spaceEach = totalSpaces / numGaps;
                int extraSpaces = totalSpaces % numGaps;
                
                for (int i = idx; i < last; i++) {
                    line += words[i];
                    if (i != last - 1) {
                        int spacesToAdd = spaceEach + (i - idx < extraSpaces ? 1 : 0);
                        line += string(spacesToAdd, ' ');
                    }
                }
            }
            
            result.push_back(line);
            idx = last;
        }
        
        return result;
    }
};