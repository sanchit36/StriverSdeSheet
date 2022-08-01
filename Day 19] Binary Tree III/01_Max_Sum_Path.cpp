class Solution
{
    int solve(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left, maxi);
        int r = solve(root->right, maxi);
        int val = root->val;
        maxi = max({maxi, val, val + l, val + r, val + l + r});
        return max({val, val + l, val + r});
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};