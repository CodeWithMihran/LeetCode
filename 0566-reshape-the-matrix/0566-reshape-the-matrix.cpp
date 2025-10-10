class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        if (m == 0) return mat;
        int n = mat[0].size();
        int total = m * n;
        if (total != r * c) return mat;

        vector<vector<int>> res(r, vector<int>(c));
        for (int k = 0; k < total; ++k) {
            int origRow = k / n;
            int origCol = k % n;
            int newRow = k / c;
            int newCol = k % c;
            res[newRow][newCol] = mat[origRow][origCol];
        }
        return res;
    }
};
