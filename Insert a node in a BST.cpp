Node* insert(Node* root, int Key) 
{
    if(root==NULL)
    {
       Node *temp= new Node(Key);
       root=temp;
       return root;
    }
    if(root->data==Key)
       return root;
    if(root->data<Key)
    {
       root->right= insert(root->right,Key);
       return root;
   }
   if(root->data>Key)
   {
       root->left= insert(root->left,Key);
       return root;
   }
}
