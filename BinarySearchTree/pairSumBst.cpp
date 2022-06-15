#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void inorder(BinaryTreeNode<int> *root, unordered_map<int, int> &mp)
{
    if (!root)
        return;

    inorder(root->left, mp);
    mp[root->data]++;
    inorder(root->right, mp);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_map<int, int> mp;
    inorder(root, mp);

    for (auto x : mp)
    {
        int num = k - x.first;
        mp[x.first]--;
        if (mp.find(num) != mp.end() && mp[num] >= 1)
        {
            return true;
        }
        mp[x.first]++;
    }
    return false;
}