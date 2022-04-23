    vector<int> verticalOrder(Node *root)
    {
        //distance --> (Level --> vector )
        map<int,map<int,vector<int>>>mp;
        queue<pair<Node*,pair<int,int>>>q;
        //Node --> (Level --> distance )
        //Distance Level Pair is required because 
        //first of all we desperately needs distance for left negative 
        //for right positive and if same distance at any instance first 
        //we will print level zero top to dwon verticaltracerse 
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<Node*,pair<int,int>>p=q.front();
            Node* front=p.first;
            q.pop();
            int dis=p.second.first;
            int lvl=p.second.second;
            mp[dis][lvl].push_back(front->data);
            if(front->left)
                q.push(make_pair(front->left,make_pair(dis-1,lvl+1)));
            if(front->right)
                q.push(make_pair(front->right,make_pair(dis+1,lvl+1)));
        }
        vector<int>ans;
        for(auto i:mp)
        {
            for(auto j:i.second)
            {
                for(int k:j.second)
                   ans.push_back(k);
            }
        }
        return ans;
    }
