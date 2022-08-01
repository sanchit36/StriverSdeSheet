bool solve(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
        return p == q;
    return (p->data == q->data) && solve(p->left, q->right) && solve(p->right, q->left);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return solve(root->left, root->right);
}