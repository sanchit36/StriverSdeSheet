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

// Recursive
void preOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

// Iterative
void preOrderIterative(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if (root->right)
            st.push(root->right);
        if (root->left)
            st.push(root->left);
    }
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    preOrderIterative(root, ans);
    return ans;
}