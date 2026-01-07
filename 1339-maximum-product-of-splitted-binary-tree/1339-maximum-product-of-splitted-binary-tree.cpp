/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<long long> sums;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* node) {
        if (!node) return 0;
        long long s = node->val + dfs(node->left) + dfs(node->right);
        sums.push_back(s);
        return s;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        long long ans = 0;
        for (long long x : sums)
            ans = max(ans, x * (total - x));
        return ans % MOD;
    }
};