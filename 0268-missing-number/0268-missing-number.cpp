class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expSum = n*(n+1)/2;
        int realSum = 0;
        for(int val: nums){
            realSum += val;
        }
        return expSum - realSum;
    }
};