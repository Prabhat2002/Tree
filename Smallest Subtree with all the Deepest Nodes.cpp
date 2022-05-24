class Solution 
{
  public:
    int height(TreeNode* root)
    {
        if(root==NULL) 
            return 0;
        int l=1+height(root->left);
        int r=1+height(root->right);
        return max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        if(!root->left && !root->right) 
            return root;
        TreeNode* ans;
        while(1)
        {
            int l=height(root->left);
            int r=height(root->right);
            if(l==r)
            {
                ans=root; 
                break;
            }
            else if(l>r)
                root=root->left;
            else 
                root=root->right;
        }
      return ans;
    }
};
