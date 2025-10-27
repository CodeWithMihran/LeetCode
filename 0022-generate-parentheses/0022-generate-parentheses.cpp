class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backtrack(res, path, 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string>& res, string& path, int open, int close, int n) {
        if ((int)path.size() == 2 * n) {
            res.push_back(path);
            return;
        }

        if (open < n) {
            path.push_back('(');
            backtrack(res, path, open + 1, close, n);
            path.pop_back();
        }

        if (close < open) {
            path.push_back(')');
            backtrack(res, path, open, close + 1, n);
            path.pop_back();
        }
    }
};