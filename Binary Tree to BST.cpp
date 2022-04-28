    Node* make_BST(vector<int>&ans,int i,int j)
    {
        if(i<=j)
        {
            int m=(i+j)/2;
            Node* root=new Node(ans[m]);
            root->left=make_BST(ans,i,m-1);
            root->right=make_BST(ans,m+1,j);
            return root;
        }
        return NULL;
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>ans;
        preorder(root,ans);
        sort(ans.begin(),ans.end());
        Node* node=make_BST(ans,0,ans.size()-1);
        return node;
    }
    void preorder(Node* root,vector<int>&ans)
    {
        if(root==NULL)
           return;
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
