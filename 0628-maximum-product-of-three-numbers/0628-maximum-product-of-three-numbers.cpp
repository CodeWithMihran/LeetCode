class Solution {
public:
    static int maximumProduct(vector<int>& nums) {
        int a=nums[0], b=nums[1], c=nums[2];
        // 3-element sort 
        auto [x2, x0]=ranges::minmax({a, b, c});
        int x1=(a+b+c)-x0-x2;
        int m0=x2, m1=x1;

        const int n=nums.size();
        for (int i=3; i<n; i++) {
            const int x=nums[i];
            bool le0=x>=x0, le1=(!le0) && (x>=x1), le2=(x<x1) && (x>=x2);
            // Update by using -1 mask
            x2+=(-le0 & (x1-x2))+(-le1 & (x1-x2))+(-le2 & (x-x2));
            x1+=(-le0 & (x0-x1))+(-le1 & (x-x1));
            x0+=(-le0 & (x-x0));

            // Track 2 smallest values
            bool ge0=x<=m0, ge1=!ge0 && (x<=m1);

            m1+=(-ge0 & (m0-m1))+(-ge1 & (x-m1));
            m0+=(-ge0 & (x-m0));
        }

        return max(x0*x1*x2, x0*m0*m1);
    }
};