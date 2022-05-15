class Solution 
{
 public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
         if(root==NULL)
             return NULL;
         root->left=removeLeafNodes(root->left,target);
         root->right=removeLeafNodes(root->right,target);
         //Postorder Traversal after getting node as leaf we will make it as root as NULL 
         if(root->left==NULL && root->right==NULL && root->val==target)
             return NULL; 
         return root;
    }
};
