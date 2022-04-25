 TreeNode* recur(vector<int>&nums,int i ,int j)
    {
      if(i<=j)
      {
        int max=*max_element(nums.begin()+i, nums.begin()+j+1);
        TreeNode* root=new TreeNode(max);
        int ind=-1;
        for (int i=0;i<=j;i++) 
        {
            if(nums[i]==max) 
            {
                ind=i;
                break;
            }
        }
        root->left=recur(nums,i,ind-1);
        root->right=recur(nums,ind+1,j);
        return root;
      }
      return NULL;  
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.size()==0)
            return NULL;
        return recur(nums,0,nums.size()-1);
    }
};
