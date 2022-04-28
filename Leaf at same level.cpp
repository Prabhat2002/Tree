class Solution
{
  public:
    map<int,vector<int>>mp;
    void traverse(Node* root,int lvl)
    {
        if(root==NULL)
           return;
        if(root->left==NULL && root->right==NULL)
        {
            mp[lvl].push_back(root->data);
            return;
        }
        traverse(root->left,lvl+1);
        traverse(root->right,lvl+1);
    }
    bool check(Node *root)
    {
        traverse(root,0);
        if(mp.size()==1)
           return 1;
        return 0;
    }
};
