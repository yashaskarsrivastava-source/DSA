class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        // All characters matched
        if (idx == word.size()) return true;

        // Out of bounds or character mismatch
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] != word[idx]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all 4 directions
        bool found = backtrack(board, word, idx + 1, row + 1, col) ||
                     backtrack(board, word, idx + 1, row - 1, col) ||
                     backtrack(board, word, idx + 1, row, col + 1) ||
                     backtrack(board, word, idx + 1, row, col - 1);

        // Restore the cell (backtrack)
        board[row][col] = temp;

        return found;
    }
};