class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 && col==0)continue;
                int down=0;
                if(row>0)down+=dp[row-1][col];
                int right=0;
                if(col>0)right+=dp[row][col-1];
                dp[row][col]=down+right;
            }
        }
        return dp[m-1][n-1];
    }
};