 int sum=0;
    void call(TreeNode* root)
    {
        if(root==NULL)
            return;
        call(root->right);
        sum+=root->val;
        root->val=sum;
        call(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        call(root);  
        return root;
    }
