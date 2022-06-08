/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
            data = 0;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
            data = val;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
            data = val;
            this->neighbours = neighbours;
        }
    };

******************************************************************************/
void dfs(graphNode *curr, graphNode *node, vector<graphNode *> &vis)
{
    vis[node->data] = node;
    for (auto it : curr->neighbours)
    {
        if (vis[it->data] == NULL)
        {
            graphNode *newNode = new graphNode(it->data);
            (node->neighbours).push_back(newNode);
            dfs(it, newNode, vis);
        }
        else
        {
            (node->neighbours).push_back(vis[it->data]);
        }
    }
}
graphNode *cloneGraph(graphNode *node)
{
    if (node == NULL)
        return NULL;
    vector<graphNode *> vis(100000);
    graphNode *copy = new graphNode(node->data);
    vis[node->data] = copy;

    for (auto it : node->neighbours)
    {
        if (vis[it->data] == NULL)
        {
            graphNode *newNode = new graphNode(it->data);
            (copy->neighbours).push_back(newNode);
            dfs(it, newNode, vis);
        }
        else
        {
            (copy->neighbours).push_back(vis[it->data]);
        }
    }

    return copy;
}