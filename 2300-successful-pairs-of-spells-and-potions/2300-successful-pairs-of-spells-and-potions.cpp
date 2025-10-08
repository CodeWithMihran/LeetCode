class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<long long> P(potions.begin(), potions.end());
        sort(P.begin(), P.end());

        vector<int> ans;
        ans.reserve(spells.size());

        for (int s : spells) {
            if (s == 0) {
                ans.push_back(0);
                continue;
            }
            long long need = (success + (long long)s - 1) / (long long)s;

            auto it = lower_bound(P.begin(), P.end(), need);
            int idx = (int)(it - P.begin());
            ans.push_back(n - idx);
        }
        return ans;
    }
};