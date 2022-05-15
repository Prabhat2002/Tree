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
    bool isEvenOddTree(TreeNode* root) 
    {
        vector<vector<int>>ans=levelOrder(root);
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            vector<int>vec=ans[i];
            if(i%2==0)
            {
                if(vec.size()==1)
                {
                    if(vec.back()%2==0)
                        return false;
                }
                for(int j=1;j<vec.size();j++)
                {
                    if(vec[j]%2==1 && vec[j-1]%2==1 && vec[j]>vec[j-1])
                        continue;
                    else
                        return 0;
                }
            }
            else
            {
                if(vec.size()==1)
                {
                    if(vec.back()%2==1)
                        return false;
                }   
                for(int j=1;j<vec.size();j++)
                {
                    if(vec[j]%2==0 && vec[j-1]%2==0 && vec[j]<vec[j-1])
                        continue;
                    else
                        return 0;
                }
            }
        }
        return true;
    }
};
