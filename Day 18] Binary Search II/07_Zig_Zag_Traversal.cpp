#include <bits/stdc++.h>
using namespace std;

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool isFront = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *it = q.front();
            q.pop();
            int index = isFront ? i : size - i - 1;
            level[index] = it->data;
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
        isFront = !isFront;
        for (auto num : level)
            ans.push_back(num);
    }
    return ans;
}