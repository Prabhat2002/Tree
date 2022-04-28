 int make(Node* root)
    {
       if(root==NULL)
          return 0;
       int left=make(root->left);
       int right=make(root->right);
       int data=root->data;
       root->data=left+right;
       return data+left+right;
    }
    void toSumTree(Node *node)
    {
       int data=make(node);
    }
