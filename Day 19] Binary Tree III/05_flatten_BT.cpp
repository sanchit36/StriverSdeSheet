class Solution
{
    TreeNode<int> *prev = NULL;

public:
    void flatten(TreeNode<int> *root)
    {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = prev;
        prev = root;
    }
};
