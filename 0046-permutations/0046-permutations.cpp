class Solution {
public:

    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans){
        int n = nums.size();
        if(idx == n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            swap(nums[idx],nums[i]);
            getPerms(nums, idx+1, ans);
            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};