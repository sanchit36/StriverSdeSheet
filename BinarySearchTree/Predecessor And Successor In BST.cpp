/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int successor = -1;
    int predecessor = -1;
    BinaryTreeNode<int> *cur = root;
    while (root)
    {
        if (key <= root->data)
        {
            root = root->left;
        }
        else
        {
            predecessor = root->data;
            root = root->right;
        }
    }
    root = cur;
    while (root)
    {
        if (key >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root->data;
            root = root->left;
        }
    }

    return {predecessor, successor};
}
