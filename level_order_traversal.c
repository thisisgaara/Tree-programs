
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

int height(node * root)
    {
    if(root == NULL)return 0;
    int lheight = height(root -> left);
    int rheight = height (root -> right);
    if(lheight > rheight)
        return lheight+1;
    return rheight+1;
}
void print_level(node* root, int level)
    {
        if(root == NULL) return;
        if(level == 1) printf("%d ", root -> data);
        if(level == 0) return;
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
void LevelOrder(node * root)
{
  int i;
  int h = height(root);
  for (i = 1; i <=h; i++)
      print_level(root, i);
  
}
