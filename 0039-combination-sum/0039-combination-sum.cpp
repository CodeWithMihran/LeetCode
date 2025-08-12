class Solution {
public:
    set<vector<int>> s;
    void getAllComb(vector<int>& candidates, int idx, vector<int>& combin, vector<vector<int>>& ans,int target){
        int n = candidates.size();
        if(idx == n || target<0){
            return;
        }
        if(target == 0){
            if(s.find(combin) == s.end()){
                ans.push_back({combin});
                s.insert(combin);
            }
            return;
        }
        combin.push_back(candidates[idx]);
        getAllComb(candidates, idx+1, combin, ans, target-candidates[idx]);
        getAllComb(candidates, idx, combin, ans, target-candidates[idx]);
        combin.pop_back();
        getAllComb(candidates, idx+1, combin, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combin;
        vector<vector<int>> ans;
        getAllComb(candidates,0, combin, ans, target);
        return ans;
    }
};