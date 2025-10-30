class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int start, int target, vector<int>& path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            path.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i], path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(candidates, 0, target, path);
        return res;
    }
};