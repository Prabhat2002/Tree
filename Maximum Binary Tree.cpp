class Solution 
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.size()==0)
            return NULL;
        int max=*max_element(nums.begin(), nums.end());
        TreeNode* root=new TreeNode(max);
        int ind=-1;
        for (int i=0;i<nums.size();i++) 
        {
            if(nums[i]==max) 
            {
                ind=i;
                break;
            }
        }
        vector<int>prefix(nums.begin(),nums.begin()+ind);
        vector<int>suffix(nums.begin()+ind+1,nums.end());
        root->left=constructMaximumBinaryTree(prefix);
        root->right=constructMaximumBinaryTree(suffix);
        return root;
    }
};
