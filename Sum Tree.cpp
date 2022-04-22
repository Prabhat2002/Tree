 int sum(Node* root)
    {
        if(root==NULL)
             return 0;
        if(root->left==NULL&&root->right==NULL)
             return root->data;
        int left=sum(root->left);
        int right=sum(root->right);
        if(left==-1 || right==-1)
            return -1;
        return root->data!=left+right?-1:root->data;
    }
    bool isSumTree(Node* root)
    {
        if(root==NULL)
           return 1;
        return sum(root)!=-1;
    }
