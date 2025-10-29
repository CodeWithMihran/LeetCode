class Solution {
public:
    int findLeft(const vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, idx = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else {
                if (nums[mid] == target) idx = mid;
                hi = mid - 1;
            }
        }
        return idx;
    }

    int findRight(const vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, idx = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) hi = mid - 1;
            else {
                if (nums[mid] == target) idx = mid;
                lo = mid + 1;
            }
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { findLeft(nums, target), findRight(nums, target) };
    }
};