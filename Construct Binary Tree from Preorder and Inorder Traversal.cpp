class Solution 
{
 public:
    int find_pos(int val,vector<int>&in)
    {
        for(int i=0;i<in.size();i++)
        {
            if(val==in[i])
               return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>&in,vector<int>& pre,int &i,int j,int n,int size)
    {
        if(i>=size || j>n)
           return NULL;
        int val=pre[i++];
        TreeNode* ans=new TreeNode(val);
        int k=find_pos(val,in);
        ans->left=solve(in,pre,i,j,k-1,size);
        ans->right=solve(in,pre,i,k+1,n,size);
        return ans;
    }
    TreeNode* buildTree(vector<int>& pre,vector<int>& in) 
    {
         int n=pre.size();
         int cur=0;
         TreeNode *ans=solve(in,pre,cur,0,n-1,n);
         return ans;
    }
};
