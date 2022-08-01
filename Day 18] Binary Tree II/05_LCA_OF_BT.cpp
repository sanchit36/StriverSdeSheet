// LCA Lowest Common Ancestor
// BASE CASE
// if Root == NULL or Root == X or Root == Y return Root
// Left call and Right call
// Left == NULL Return Right, must be in right
// Right == NULL Return Left, must be in left
// If Both are Not Null return root joining point

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if (!root)
        return -1;
    if (root->data == x or root->data == y)
        return root->data;

    int l = lowestCommonAncestor(root->left, x, y);
    int r = lowestCommonAncestor(root->right, x, y);

    if (l != -1 and r != -1)
        return root->data;
    if (l != -1)
        return l;
    return r;
}
