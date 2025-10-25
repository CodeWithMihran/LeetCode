class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(const vector<vector<int>>& H, vector<vector<bool>>& seen, int r, int c) {
        seen[r][c] = true;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen[nr][nc]) {
                if (H[nr][nc] >= H[r][c]) {
                    dfs(H, seen, nr, nc);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int j = 0; j < n; ++j) dfs(heights, pac, 0, j);
        for (int i = 0; i < m; ++i) dfs(heights, pac, i, 0);

        for (int j = 0; j < n; ++j) dfs(heights, atl, m-1, j);
        for (int i = 0; i < m; ++i) dfs(heights, atl, i, n-1);

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};