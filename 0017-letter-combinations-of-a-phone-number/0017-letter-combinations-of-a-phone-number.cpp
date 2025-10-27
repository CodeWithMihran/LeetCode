class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> res;
        string path;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                res.push_back(path);
                return;
            }

            string letters = phone[digits[index] - '0'];
            for (char ch : letters) {
                path.push_back(ch);
                backtrack(index + 1);
                path.pop_back();
            }
        };
        backtrack(0);
        return res;
    }
};