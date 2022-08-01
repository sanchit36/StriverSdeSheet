// Boundary Traversal is Left then Leafs and Right is Reverse order
// So for Left Boundary do PreOrder
// for Leaves Do InOrder
// For Right Boundary do PostOrder

void leftBoundaryExludingLeaves(TreeNode<int> *node, vector<int> &ds)
{
    if (node == NULL)
        return;
    if (node->left != NULL or node->right != NULL)
        ds.push_back(node->data);
    if (node->left)
        leftBoundaryExludingLeaves(node->left, ds);
    else if (node->right)
        leftBoundaryExludingLeaves(node->right, ds);
}

void leafNodes(TreeNode<int> *node, vector<int> &ds)
{
    if (node == NULL)
        return;
    leafNodes(node->left, ds);
    if (node->left == NULL and node->right == NULL)
    {
        ds.push_back(node->data);
    }
    leafNodes(node->right, ds);
}

void rightBoundaryExludingLeaves(TreeNode<int> *node, vector<int> &ds)
{
    if (node == NULL)
        return;
    if (node->right)
        rightBoundaryExludingLeaves(node->right, ds);
    else if (node->left)
        rightBoundaryExludingLeaves(node->left, ds);
    if (node->left != NULL or node->right != NULL)
        ds.push_back(node->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    if (root->left == NULL and root->right == NULL)
        return ans;
    leftBoundaryExludingLeaves(root->left, ans);
    leafNodes(root, ans);
    rightBoundaryExludingLeaves(root->right, ans);
    return ans;
}