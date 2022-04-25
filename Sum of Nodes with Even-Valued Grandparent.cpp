class Solution 
{
 public:
    int ans=0;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
           return;
        if(root->val%2==0)
        {
            if(root->left)
            {
                if(root->left->left)
                    ans=ans+root->left->left->val;
                if(root->left->right)
                    ans=ans+root->left->right->val;
            }
            if(root->right)
            {
                if(root->right->left)
                    ans=ans+root->right->left->val;
                if(root->right->right)
                    ans=ans+root->right->right->val;
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) 
    {
        dfs(root); 
        return ans;
    }
};
