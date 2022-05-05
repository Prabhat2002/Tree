vector<int> reverseLevelOrder(Node *root)
{
        if(!root)
            return {};
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty())
        {
            Node *temp=q.front();
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
                v.push_back(temp->data);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        vector<int>res;
        for(int i=ans.size()-1;i>=0;i--)
        {
            for(int j=0;j<ans[i].size();j++)
                 res.push_back(ans[i][j]);
        }
        return res;
}
