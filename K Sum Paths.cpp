    void solve(Node *root,int k,vector<int>nums)
    {
        if(root==NULL)
           return;
        nums.push_back(root->data);
        solve(root->left,k,nums);
        solve(root->right,k,nums);
        int sum=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum=sum+nums[i];
            if(sum==k)
              ans++;
        }
    }
    int sumK(Node *root,int k)
    {
        vector<int>nums;
        solve(root,k,nums);
        return ans;
    }
