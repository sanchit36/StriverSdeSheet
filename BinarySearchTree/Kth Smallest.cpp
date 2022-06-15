/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int> in;
    inorder(root, in);
    if (k > in.size())
        return -1;
    return in[k - 1];
}