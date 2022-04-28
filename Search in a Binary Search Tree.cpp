class Solution 
{
 public:
    TreeNode* ans=NULL;
    void find(TreeNode* root, int val)
    {
        if(root==NULL)
            return;
        if(root->val==val)
        {
            ans=root;
            return;
        }
        if(root->val>val)
           find(root->left,val);
        else
           find(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        find(root,val);
        return ans;
    }
};
