class Solution 
{
  public:
    int sum(TreeNode* root, int& cnt)
    {
        if(root==NULL) 
            return 0;
        cnt++;
        int left = sum(root->left,cnt);
        int right = sum(root->right,cnt);
        return (root->val + left + right);
    }
    void solve(TreeNode* root,int &ans)
    {
        if(root==NULL) 
            return;
        int cnt=0;
        //finding sum and node value 
        int avg=(sum(root,cnt))/cnt;
        if(avg==root->val) 
            ans++;
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
