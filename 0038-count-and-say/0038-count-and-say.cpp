class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "1";
        for (int k = 2; k <= n; ++k) {
            string next;
            int i = 0;
            while (i < s.size()) {
                int j = i + 1;
                while (j < s.size() && s[j] == s[i]) ++j;
                int count = j - i;
                next += to_string(count);
                next.push_back(s[i]);
                i = j;
            }
            s = move(next);
        }
        return s;
    }
};