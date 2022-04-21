    vector <int> zigZagTraversal(Node* root)
    {
        if(root==NULL)
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
        for(int i=0;i<ans.size();i++)
        {
           vector<int>v1=ans[i];    
           if(i%2)
              reverse(v1.begin(),v1.end());
           for(int j=0;j<v1.size();j++)
               res.push_back(v1[j]);
        }
      return res;	
    }
