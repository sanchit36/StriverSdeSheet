/*
Following is the structure of Tree Node

class TreeNode
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/
#include <bits/stdc++.h>

void postOrderTrav(TreeNode *curr, vector<int> &postOrder)
{
    if (curr == NULL)
        return;
    postOrderTrav(curr->left, postOrder);
    postOrderTrav(curr->right, postOrder);
    postOrder.push_back(curr->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postOrder;
    postOrderTrav(root, postOrder);
    return postOrder;
}
