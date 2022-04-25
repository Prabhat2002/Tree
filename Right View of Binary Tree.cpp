 vector<int> rightView(Node *root)
    {
        if(root==NULL)
            return {};
        vector<vector<int>>res;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty())
        {
            Node* temp=q.front();
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
                v.push_back(temp->data);
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
