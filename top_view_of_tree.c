void print_left(node *root)
    {
    if(root == NULL) return;
    print_left(root->left);
    printf("%d ", root-> data);
}
void print_right(node *root)
    {
    if(root == NULL) return;
      printf("%d ", root-> data);
    print_right(root->right);
}

void top_view(node * root)
{
    print_left(root->left);
    printf("%d ", root -> data);
    print_right(root->right);
      
  
}
