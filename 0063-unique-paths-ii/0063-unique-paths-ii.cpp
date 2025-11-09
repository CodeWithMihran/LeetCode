class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return 0;

        int row = grid.size();
        int col = grid[0].size();

        if(grid[row-1][col-1]==1)return 0;

        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j< col ; j++){
                if(grid[i][j]==1)grid[i][j]=-1;
            }
        }

        grid[row-1][col-1]=1;

        for(int i = row-1 ; i>=0 ; i--){
            for(int j = col-1 ; j>=0 ; j--){
                if(i == row-1 && j==col-1)continue;
                if(grid[i][j]==-1)continue; 
                int bottom = 0;
                if(i+1 < row && grid[i+1][j]!=-1){
                    bottom = grid[i+1][j];
                }
                int right = 0;
                if(j+1 < col && grid[i][j+1]!=-1){
                    right = grid[i][j+1];
                }
                long long ans = (long long)bottom + (long long)right;

                grid[i][j] = (int)ans;
            }
        }
        return grid[0][0];
    }
};