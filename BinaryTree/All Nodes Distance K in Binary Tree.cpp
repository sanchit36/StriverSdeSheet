class Solution
{
    void mark_parents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parents)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            if (it->left)
            {
                parents[it->left] = it;
                q.push(it->left);
            }
            if (it->right)
            {
                parents[it->right] = it;
                q.push(it->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parents;
        mark_parents(root, parents);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int dis = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (dis++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();
                if (it->left && !visited[it->left])
                {
                    q.push(it->left);
                    visited[it->left] = true;
                }
                if (it->right && !visited[it->right])
                {
                    q.push(it->right);
                    visited[it->right] = true;
                }
                if (parents[it] && !visited[parents[it]])
                {
                    q.push(parents[it]);
                    visited[parents[it]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};