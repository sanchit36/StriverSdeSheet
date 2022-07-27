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

void inOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

void inOrderIterative(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    stack<TreeNode *> st;
    while (true)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                return;
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            root = root->right;
        }
    }
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    inOrderIterative(root, ans);
    return ans;
}