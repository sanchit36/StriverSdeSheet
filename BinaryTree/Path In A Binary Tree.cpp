bool preOrder(TreeNode<int> *node, int x, vector<int> &path)
{
    if (node == NULL)
        return false;
    path.push_back(node->data);
    if (node->data == x)
        return true;
    if (preOrder(node->left, x, path) || preOrder(node->right, x, path))
        return true;
    path.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path;
    if (!root)
        return path;
    preOrder(root, x, path);
    return path;
}
