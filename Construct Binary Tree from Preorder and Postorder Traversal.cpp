class Solution 
{
 public:
    int i = 0;
    TreeNode* help(vector<int>& pre, vector<int>& post,int start,int end)
    {
        if(start>end || i>=pre.size()) 
            return NULL;
        int j =-1;
        for(int k = start;k<=end;k++)
        {
            if(pre[i]==post[k])
            {
                j=k;
                break;
            }
        }
        if(j==-1) 
            return NULL;
        i++;
        //finding root node index in post array  and later on distribute it into two parts.
        TreeNode* root=new TreeNode(post[j]);
        root->left=help(pre,post,start,j-1);
        root->right=help(pre,post,start,j-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        return help(pre,post,0,post.size()-1);
    }
};
