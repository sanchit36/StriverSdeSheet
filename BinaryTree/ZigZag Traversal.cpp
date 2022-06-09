vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> zigzag;
    if (root == NULL)
        return zigzag;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            int index = (leftToRight) ? i : (size - i - 1);
            row[index] = node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        for (auto x : row)
            zigzag.push_back(x);
    }
    return zigzag;
}
