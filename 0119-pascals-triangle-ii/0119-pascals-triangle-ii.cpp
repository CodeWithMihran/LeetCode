class Solution {
public:
vector<int>rowprint(int row){
    long long  c =1;
    vector<int>ans;
    ans.push_back(1);
    for(int col = 1 ; col <=row;col++){
       c = c * (row-col+1) / col;
       
       ans.push_back(c);

    }
    return ans;            
}
    vector<int> getRow(int rowIndex) {
        return rowprint(rowIndex);
    }
};