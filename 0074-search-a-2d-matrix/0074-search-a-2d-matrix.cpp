class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     for(int i=0; i<matrix.size(); i++){
    //     int st = 0, end = matrix[i].size()-1;
    //     while(st <= end){
    //         int mid = st + (end-st)/2;
    //         if(matrix[i][mid] == target){
    //             return true;
    //         }
    //         if(matrix[i][mid] > target){
    //             end = mid-1;
    //         }
    //         else{
    //             st = mid+1;
    //         }
    //     }
    // }
    // return false;
    // }
    bool searchinRow(vector<vector<int>> matrix, int target, int row){
    int n = matrix[0].size();
    int st = 0, end = n-1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(target == matrix[row][mid]){
            return true;
        }
        if(target > matrix[row][mid]){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> matrix, int target){
    int m = matrix.size(), n = matrix[0].size();
    int stRow = 0 , endRow = m-1;
    while(stRow <= endRow){
        int midRow = stRow + (endRow-stRow)/2;
        if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
            return searchinRow(matrix,target,midRow);
        }
        if(target < matrix[midRow][0]){
            endRow = midRow-1;
        }
        else{
            stRow = midRow+1;
        }
    }
    return false;
}
};