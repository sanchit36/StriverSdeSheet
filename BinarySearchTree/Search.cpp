/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(!root) return false;
    while(root) {
        if(root->data == x) return true;
        if(x>root->data) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return false;
}