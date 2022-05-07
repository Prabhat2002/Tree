Node* buildtree(vector<int>&nums,int i,int j)
{
    if(i<=j)
    {
        int mid=(i+j)/2;
        Node* root=new Node(nums[mid]);
        root->left=buildtree(nums,i,mid-1);
        root->right=buildtree(nums,mid+1,j);
        return root;
    }
    return NULL;
}
void inorder(Node* root,vector<int>&nums)
{
    if(root==NULL)
       return;
    inorder(root->left,nums);
    nums.push_back(root->data);
    inorder(root->right,nums);
}
Node* buildBalancedTree(Node* root)
{
    vector<int>nums;
	inorder(root,nums);
	return buildtree(nums,0,nums.size()-1);
}
