unordered_map<string, int>m;
vector <Node*>v;
string solve(Node*root)
{
   if(!root) 
       return "%";//for differenciating (3->(L->4) && 3->(R->5)) && ((3->(L->4)->(R->5)) and many more
   string s="";
   if(!root->left and !root->right)
   {
      s=to_string(root->data);
      m[s]++;
   }
   s=s+to_string(root->data);
   s=s+solve(root->left);
   s=s+solve(root->right);
   if(m[s]==1)
        v.push_back (root);
   m[s]++;
   return s;
}
vector<Node*> printAllDups(Node* root)
{
   m.clear();
   v.clear();
   solve(root);
   return v;
}
