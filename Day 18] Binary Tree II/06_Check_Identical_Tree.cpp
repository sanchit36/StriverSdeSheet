// IDEA ANY Traversal MUST ME SAME
// USING DFS
// if Root1 == NULL and Root2 == NULL return true
// if Root1 == NULL or Root2 == NULL return false
// return (Root1->data == Root2->data)
//        && identicalTrees(Root1->left, Root2->left)
//        && identicalTrees(Root1->right, Root2->right);

bool identicalTrees(BinaryTreeNode<int> *root1,
                    BinaryTreeNode<int> *root2)
{
    if (root1 == NULL and root2 == NULL)
        return true;
    if (root1 == NULL or root2 == NULL)
        return false;
    return (root1->data == root2->data) &&
           identicalTrees(root1->left, root2->left) &&
           identicalTrees(root1->right, root2->right);
}