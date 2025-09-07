class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int tmp = image[i][left] ^ 1;
                image[i][left] = image[i][right] ^ 1;
                image[i][right] = tmp;
                left++;
                right--;
            }
        }
        return image;
    }
};