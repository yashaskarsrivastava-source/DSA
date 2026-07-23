class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue; // skip empty parts and current-directory markers
            } else if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }

        string result;
        for (const string& dir : stack) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};