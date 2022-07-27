/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
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


************************************************************/
#include <bits/stdc++.h>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans(3);
    if (root == NULL)
        return ans;
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        switch (it.second)
        {
        case 1:
            ans[1].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left)
            {
                st.push({it.first->left, 1});
            }
            break;
        case 2:
            ans[0].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right)
            {
                st.push({it.first->right, 1});
            }
            break;
        case 3:
            ans[2].push_back(it.first->data);
            break;
        }
    }
    return ans;
}