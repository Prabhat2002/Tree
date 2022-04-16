class Solution 
{
 public:
    TreeNode*  mergesort(vector<int>& nums,int i,int j)
    {
        if(i<=j)
        {
            int m=(i+j)/2;
            TreeNode *root=new TreeNode(nums[m]);
            root->left=mergesort(nums,i,m-1);
            root->right=mergesort(nums,m+1,j);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
           return mergesort(nums,0,nums.size()-1);
    }
};
