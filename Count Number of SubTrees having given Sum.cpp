int solve(Node* root,int x,int &ans)
{
   if(root==NULL)
       return 0;
   int left=solve(root->left,x,ans);
   int right=solve(root->right,x,ans);
   int cur=root->data+left+right;
   if(cur==x)
      ans++;
   return cur;
}
int countSubtreesWithSumX(Node* root, int x)
{
    int ans=0;
    int z=solve(root,x,ans);
    return ans;   
}
