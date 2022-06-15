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

class BSTiterator
{
    int curr = -1;
    vector<int> in;
    void inorder(TreeNode<int> *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        in.push_back(root->data);
        inorder(root->right);
    }

public:
    BSTiterator(TreeNode<int> *root)
    {
        inorder(root);
    }

    int next()
    {
        return in[++curr];
    }

    bool hasNext()
    {
        return in.size() > curr + 1;
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/