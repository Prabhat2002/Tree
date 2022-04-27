class Solution 
{
  public:
    int height(Node* node)
    {
        if(node==NULL)
            return 0;
        int left=height(node->left);
        int right=height(node->right);
        return max(left,right)+1;
    }    
    int diameter(Node* root) 
    {
        if(root==NULL)
           return 0;
        int d1=diameter(root->left);
        int d2=diameter(root->right);
        int h=height(root->right)+height(root->left)+1;
        return max({d1,d2,h});
    }
};
