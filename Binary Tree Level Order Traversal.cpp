class Solution 
{
 public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                ans.push_back(v);
                if(!q.empty())
                {
                    q.push(NULL);
                    v.erase(v.begin(),v.end());
                }
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
        return ans;
    }
};
