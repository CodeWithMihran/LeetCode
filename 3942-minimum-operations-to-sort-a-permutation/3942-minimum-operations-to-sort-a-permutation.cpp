class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), first = nums[0];
        span ring(nums);  // the circle, read from the cut: no search for 0
        auto reads = [&](auto head, auto tail) {  // the ring is head, then tail
            return ranges::equal(ring.first(head.size()), head) && ranges::equal(ring.subspan(head.size()), tail);
        };
        if (reads(views::iota(first, n), views::iota(0, first))) {  // counts up along the arrow
            int shift = (n - first) % n;  // where 0 sits
            return min(shift, n - shift + 2);  // walk ahead, or turn, walk back, turn back
        }
        if (reads(views::iota(0, first + 1) | views::reverse, views::iota(first + 1, n) | views::reverse)) {  // counts up against the arrow
            int shift = first;  // where 0 sits
            return min(shift + 2, n - shift);  // walk ahead and turn, or turn and walk back
        }
        return -1;
    }
};