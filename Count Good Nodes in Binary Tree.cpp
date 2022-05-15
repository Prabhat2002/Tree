
Method : 1

class Solution 
{
 public:
    vector<int>ans;
    void call(TreeNode* root,int val)
    {
        if(root==NULL)
            return;
        if(root->val>=val)
            ans.push_back(root->val);
        call(root->left,max(root->val,val));
        call(root->right,max(root->val,val));
    }
    int goodNodes(TreeNode* root) 
    {
        call(root,INT_MIN); 
        return ans.size();
    }
};

Method : 2

class Solution 
{
 public:
    void call(TreeNode* root,int val,int &ans)
    {
        if(root==NULL)
            return;
        if(root->val>=val)
            ans++;
        call(root->left,max(root->val,val),ans);
        call(root->right,max(root->val,val),ans);
    }
    int goodNodes(TreeNode* root) 
    {
        int ans=0;
        call(root,INT_MIN,ans); 
        return ans;
    }
};
