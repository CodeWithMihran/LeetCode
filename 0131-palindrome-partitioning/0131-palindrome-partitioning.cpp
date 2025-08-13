class Solution {
public:
    vector<vector<string>> res;

    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int start, string &s, vector<string> &current) {
        if (start == s.size()) {
            res.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, current);
                current.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(0, s, current);
        return res;
    }
};