
Method : 1

class Solution 
{
 public:
    vector<int>ans;
    void rightview(TreeNode* root,int level)
    {
        if(root==NULL)
            return;
        if(level==ans.size())
            ans.push_back(root->val);
        rightview(root->right,level+1);
        rightview(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        rightview(root,0);
        return ans;
    }
}

Method : 2

class Solution 
{
 public:
    vector<int> rightview(TreeNode* root)
    {
        if(root==NULL)
            return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                res.push_back(v);
                if(!q.empty())
                   q.push(NULL);
                v.erase(v.begin(),v.end());
            }
            else
            {
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        vector<int>ans;
        for(int i=0;i<res.size();i++)
            ans.push_back(res[i].back());
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        return rightview(root);
    }
};
