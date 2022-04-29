class Solution 
{
 public:
    bool check(TreeNode* root,long min_,long max_)
    {
        if(root==NULL)
            return true;
        if(root->val<max_ && root->val>min_ ) 
           return check(root->left,min_,root->val)&&check(root->right,root->val,max_);
        return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        return check(root,LONG_MIN,LONG_MAX);
    }
};
