#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(T x) : data(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, map<int, vector<int>>> ds;
    queue<pair<pair<TreeNode<int> *, int>, int>> q;
    q.push({{root, 0}, 0});
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto it = q.front();
            q.pop();
            TreeNode<int> *node = it.first.first;
            int vertical = it.first.second;
            int level = it.second;
            ds[vertical][level].push_back(node->data);
            if (node->left)
                q.push({{node->left, vertical - 1}, level + 1});
            if (node->right)
                q.push({{node->right, vertical + 1}, level + 1});
        }
    }

    for (auto vpair : ds)
    {
        for (auto lpair : vpair.second)
        {
            for (auto num : lpair.second)
                ans.push_back(num);
        }
    }

    return ans;
}

int main()
{

    return 0;
}