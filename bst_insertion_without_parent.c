/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
node*new_node (int value)
{
    node *n = (node *)malloc(sizeof(node));
    n -> data = value;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}
node * insert(node * root, int value)
{
    node* temp = root;
    node * m;
    node *n = new_node(value);
    if(root == NULL)
        {
        root = n;
        return root;
    }
    while(root != NULL)
    {
        m = root;
        if(value > root->data)
        {
            root = root -> right;
        }
        else if(value <= root ->data)
        {
            root = root -> left;
        }
    }
    if(value <= m->data)
         m -> left = n;
    else
         m -> right = n;
        

   return temp;
}
