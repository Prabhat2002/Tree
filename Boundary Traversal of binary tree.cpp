    void traverseL(Node *root,vector<int>&ans)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
           return;
        ans.push_back(root->data);
        if(root->left)
           traverseL(root->left,ans);
        else
           traverseL(root->right,ans);
    }
    void traverse(Node* root,vector<int>&ans)
    {
        if(root==NULL)
           return;
       
        traverse(root->left,ans);
         if(root->left==NULL && root->right==NULL)
        {
           ans.push_back(root->data);
           return;
        }
        traverse(root->right,ans);
    }
    void traverseR(Node *root,vector<int>&ans)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
           return;
        if(root->right)
           traverseR(root->right,ans);
        else
           traverseR(root->left,ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
           return {};
        ans.push_back(root->data);   
        traverseL(root->left,ans);
        traverse(root->left,ans);
        traverse(root->right,ans);
        traverseR(root->right,ans);
        return ans;
    }
