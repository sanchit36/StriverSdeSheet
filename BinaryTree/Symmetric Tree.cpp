bool isSameToMirror(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if (p == NULL || q == NULL)
        return p == q;
    return (p->data == q->data) && isSameToMirror(p->left, q->right) && isSameToMirror(p->right, q->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return isSameToMirror(root->left, root->right);
}