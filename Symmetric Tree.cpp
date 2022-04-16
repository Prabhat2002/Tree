class Solution 
{
 public:
    bool call(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return 1;
        if(root1==NULL || root2==NULL)
            return 0;
        return (root1->val==root2->val)&&call(root1->left,root2->right)&&call(root1->right,root2->left);
        
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return 1;
        return call(root->left,root->right);
    }
};
