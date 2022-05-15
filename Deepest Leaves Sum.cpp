Method : 1

class Solution 
{
 public:
    int deepestLeavesSum(TreeNode* root) 
    {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        while (q.size()>1)
        {
            auto curr = q.front();
            q.pop();
            if (!curr)
            {
                q.push(NULL);
                sum = 0;
                continue;
            }
            sum += curr->val;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return sum;
    }
};

Method : 2 

class Solution 
{
 public:
    int levelOrder(TreeNode* root) 
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
        int n=ans.size();
        int m=ans[n-1].size();
        int total=0;
        for(int i=0;i<m;i++)
          total=total+ans[n-1][i];
     return total;
    }
    int deepestLeavesSum(TreeNode* root) 
    {
        return levelOrder(root);
    }
};
