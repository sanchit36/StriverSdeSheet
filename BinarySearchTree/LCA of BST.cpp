/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    if (!root)
        return NULL;
    int cur = root->data;
    if (cur < P->data && cur < Q->data)
        return LCAinaBST(root->right, P, Q);
    if (cur > P->data && cur > Q->data)
        return LCAinaBST(root->left, P, Q);
    return root;
}
