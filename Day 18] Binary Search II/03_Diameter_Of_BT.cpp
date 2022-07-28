int diameterOfBinaryTree(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = diameterOfBinaryTree(root->left, maxi);
    int rh = diameterOfBinaryTree(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}

int main()
{
    int maxi = 0;
    diameterOfBinaryTree(root, maxi);
    return 0;
}