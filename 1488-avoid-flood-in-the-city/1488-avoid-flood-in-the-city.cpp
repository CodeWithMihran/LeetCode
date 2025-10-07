class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int,int> last;
        set<int> dryDays;

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryDays.insert(i);
                ans[i] = 1;
            } else {
                int lake = rains[i];
                if (last.find(lake) == last.end()) {
                    last[lake] = i;
                    ans[i] = -1;
                } else {
                    int prevDay = last[lake];
                    auto it = dryDays.upper_bound(prevDay);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    int dryDayIndex = *it;
                    ans[dryDayIndex] = lake;
                    dryDays.erase(it);
                    last[lake] = i;
                    ans[i] = -1;
                }
            }
        }
        return ans;
    }
};