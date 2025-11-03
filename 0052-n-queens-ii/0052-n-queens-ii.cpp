class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        solve(0, board, n, count);
        return count;
    }

private:
    void solve(int col, vector<string> &board, int n, int &count) {
        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, n, count);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> &board, int n) {
        int r = row, c = col;

        // Check upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Check left side
        r = row;
        c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }

        // Check lower-left diagonal
        r = row;
        c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }
};