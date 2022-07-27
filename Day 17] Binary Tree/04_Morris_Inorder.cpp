#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            // Move to the last right
            // if and only if prev->right != cur -> means tread already exists
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                // create the thread
                prev->right = cur;
                // move cur to left
                cur = cur->left;
            }
            else
            {
                // already have a thread
                prev->right = NULL;
                // print cur
                inorder.push_back(cur->data);
                // move to right
                cur = cur->right;
            }
        }
    }
    return inorder;
}

int main()
{
    return 0;
}