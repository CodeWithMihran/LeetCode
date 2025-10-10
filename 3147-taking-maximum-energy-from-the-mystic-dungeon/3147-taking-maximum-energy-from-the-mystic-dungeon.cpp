class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<long long> dp(n);
        for (int i = 0; i < n; ++i) dp[i] = energy[i];
        for (int i = n - 1 - k; i >= 0; --i) dp[i] += dp[i + k];
        long long ans = dp[0];
        for (int i = 1; i < n; ++i) if (dp[i] > ans) ans = dp[i];
        return (int)ans;
    }
};