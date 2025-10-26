class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX;
        int ans = 0;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                int diff = abs(total - target);

                if (diff < closest) {
                    closest = diff;
                    ans = total;
                }

                if (total < target)
                    left++;
                else if (total > target)
                    right--;
                else
                    return total;
            }
        }
        return ans;
    }
};