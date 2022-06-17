#include<bits/stdc++.h>
class NodeValue {
    public:
    int minVal, maxVal, size;
    NodeValue(int minVal, int maxVal, int size) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->size = size;
    }
};

NodeValue postOrder(TreeNode<int>* root) {
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
    NodeValue l = postOrder(root->left);
    NodeValue r = postOrder(root->right);
    if(l.maxVal < root->data && r.minVal > root->data) {
        // is BST
        return NodeValue(min(l.minVal, root->data), max(r.maxVal, root->data),l.size+r.size+1);
    }
    // not BST
    return NodeValue(INT_MIN, INT_MAX, max(l.size, r.size));
}

int largestBST(TreeNode<int>* root)
{
    return postOrder(root).size;
}
