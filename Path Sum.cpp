class Solution 
{
 public:
    bool hasPathSum(TreeNode* r, int sum) 
    {
         if (r==NULL) 
             return false;
         if ((r->left==NULL)&&(r->right==NULL)&&(sum-r->val==0))                                    return true;
         return(hasPathSum(r->left,sum-r->val)||hasPathSum(r->right, sum-r->val));
    }
};
