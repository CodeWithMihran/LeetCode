// Sieve
constexpr int MX = 50000;
const vector<int> PRIMES = [] {
    vector<char> comp(MX + 1);
    for (int p = 2; p * p <= MX; ++p)
        if (!comp[p])
            for (int k = p * p; k <= MX; k += p)
                comp[k] = 1;
    vector<int> primes;
    for (int p = 2; p <= MX; ++p)
        if (!comp[p])
            primes.push_back(p);
    return primes;
}();

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = ranges::max(nums);
        vector<int> freq(mx + 1);
        for (int v : nums)
            ++freq[v];

        // zeta: freq[d] = #{v : d | v}
        for (int p : PRIMES) {
            if (p > mx) break;
            for (int i = mx / p; i > 0; --i)
                freq[i] += freq[i * p];
        }

        vector<long long> g(mx + 1);  // pairs with d | gcd
        ranges::transform(freq, g.begin(), [](long long c) { return c * (c - 1) / 2; });

        // Mobius: pairs with gcd == d
        for (int p : PRIMES) {
            if (p > mx) break;
            for (int i = 1; i <= mx / p; ++i)
                g[i] -= g[i * p];
        }

        vector<long long> s(mx + 1);
        partial_sum(g.begin(), g.end(), s.begin());

        vector<int> ans(queries.size());
        ranges::transform(queries, ans.begin(), [&](long long q) {
            return int(ranges::upper_bound(s, q) - s.begin());
        });
        return ans;
    }
};