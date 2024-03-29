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
    vector<int> preorder;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right != NULL and prev->right != cur)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = cur;
                preorder.push_back(cur->data);
                cur = prev->left;
            }
            else
            {
                prev->right = NULL;
                cur = prev->right;
            }
        }
    }
    return preorder;
}
