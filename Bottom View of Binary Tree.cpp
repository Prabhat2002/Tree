vector <int> bottomView(Node *root) 
    {
        vector<int>ans;
        if(root==NULL)
           return ans;
        map<int,int>mp;
        queue<pair<Node* ,int>>pq;
        pq.push(make_pair(root,0));
        while(!pq.empty())
        {
            pair<Node* ,int>p=pq.front();
            Node* temp=p.first;
            int dis=p.second;
            // if(mp.find(dis)==mp.end())
            mp[dis]=temp->data;
            if(temp->left)
               pq.push(make_pair(temp->left,dis-1));
            if(temp->right)
               pq.push(make_pair(temp->right,dis+1));
            pq.pop();
        }
        for(auto i:mp)
           ans.push_back(i.second);
        return ans;
    }
