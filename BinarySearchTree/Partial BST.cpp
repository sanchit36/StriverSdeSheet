/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool isValidBst(BinaryTreeNode<int> *root, int minVal, int maxVal)
{
    if (!root)
        return true;
    if (root->data > maxVal || root->data < minVal)
        return false;
    return isValidBst(root->left, minVal, root->data) && isValidBst(root->right, root->data, maxVal);
}

bool validateBST(BinaryTreeNode<int> *root)
{
    return isValidBst(root, INT_MIN, INT_MAX);
}