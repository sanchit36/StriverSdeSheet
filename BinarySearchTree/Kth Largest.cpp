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
void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

int KthLargestNumber(TreeNode<int> *root, int k)
{
    vector<int> in;
    inorder(root, in);
    if (k > in.size())
        return -1;
    return in[in.size() - k];
}
