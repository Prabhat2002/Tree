class Solution 
{
 public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
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
        vector<vector<int>>ans;
        for(int i=res.size()-1;i>=0;i--)
            ans.push_back(res[i]);
        return ans;
    }
};
