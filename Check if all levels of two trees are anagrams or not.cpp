class Solution
{
    public:
    void inorder(Node* root,vector<int> &nums)
    {
       if(root==NULL) 
          return;
       inorder(root->left,nums);
       nums.push_back(root->data);
       inorder(root->right,nums);
    }
    bool areAnagrams(Node *root1, Node *root2)
    {
       vector<int> v1,v2;
       inorder(root1,v1);
       inorder(root2,v2);
       reverse(v1.begin(),v1.end());
       if(v1.size()!=v2.size()) 
          return false;
       for(int i=0;i<v1.size();i++)
       {
          if(v1[i]!=v2[i]) 
            return false;
       }
       return true;
    }
};
