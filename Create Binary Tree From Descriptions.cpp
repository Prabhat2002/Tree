TreeNode* createBinaryTree(vector<vector<int>>& nums) 
    {
       unordered_map<int,TreeNode*>mp;
       unordered_map<int,int>child,parent;
       for(int i=0;i<nums.size();i++)
       {
           if(mp.find(nums[i][0])==mp.end())
           {
               TreeNode* node=new TreeNode(nums[i][0]);
               mp[nums[i][0]]=node;
           }
           if(mp.find(nums[i][1])==mp.end())
           {
               TreeNode* node=new TreeNode(nums[i][1]);
               mp[nums[i][1]]=node;
           }
           if(nums[i][2])
              mp[nums[i][0]]->left=mp[nums[i][1]];
           else
              mp[nums[i][0]]->right=mp[nums[i][1]];
           parent[nums[i][0]]++;
           child[nums[i][1]]++;
       }
       
       for(auto i:mp)
       {
           if((parent.find(i.first)!=parent.end())&&(child.find(i.first)==child.end()))
               return i.second;
       }
      return NULL;
    }
