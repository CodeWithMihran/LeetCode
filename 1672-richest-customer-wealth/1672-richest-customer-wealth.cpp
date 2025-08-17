class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        int m = accounts.size();
        int n = accounts[0].size();
        for(int i=0; i<m; i++){
            int n = accounts[i].size();
            int sum = 0;
            for(int j=0; j<n; j++){
                sum += accounts[i][j];
            }
            maxWealth = max(sum, maxWealth);
        }
        return maxWealth;
    }
};