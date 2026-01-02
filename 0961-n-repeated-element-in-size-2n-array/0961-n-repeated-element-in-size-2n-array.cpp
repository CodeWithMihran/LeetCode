class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        int n = nums.size();
        for (int distance = 1; distance <= 3; ++distance) {
            for (int i = 0; i < n - distance; ++i) {
                if (nums[i] == nums[i + distance]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};