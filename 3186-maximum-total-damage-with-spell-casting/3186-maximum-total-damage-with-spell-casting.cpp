class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {

        map<long long, long long> sum;
        for (int v : power) sum[(long long)v] += (long long)v;


        vector<pair<long long,long long>> arr;
        arr.reserve(sum.size());
        for (auto &p : sum) arr.emplace_back(p.first, p.second);

        int n = (int)arr.size();
        if (n == 0) return 0LL;

        vector<long long> dp(n+1, 0LL);

        for (int i = 1; i <= n; ++i) {
            long long val = arr[i-1].first;
            long long take = arr[i-1].second;

            int lo = 0, hi = i - 2, idx = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (arr[mid].first <= val - 3) {
                    idx = mid + 1;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            take += dp[idx];
            dp[i] = max(dp[i-1], take);
        }

        return dp[n];
    }
};