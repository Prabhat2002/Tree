class Solution
{
    public:
    int height(struct Node* node)
    {
        if(node==NULL)
            return 0;
        return max(height(node->right),height(node->left))+1;
    }
};
