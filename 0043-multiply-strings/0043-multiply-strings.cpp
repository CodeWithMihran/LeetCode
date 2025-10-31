class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            int d1 = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int d2 = num2[j] - '0';
                int mul = d1 * d2;
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }

        string ans;
        int i = 0;
        while (i < (int)res.size() && res[i] == 0) ++i;
        for (; i < (int)res.size(); ++i) ans.push_back(char('0' + res[i]));
        return ans.empty() ? "0" : ans;
    }
};