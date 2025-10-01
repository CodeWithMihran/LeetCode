class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> resSet;
        for (int x : nums2) {
            if (s1.count(x)) resSet.insert(x);
        }
        vector<int> res;
        res.reserve(resSet.size());
        for (int x : resSet) res.push_back(x);
        return res;
    }
};