/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

int is_leaf(node *root)
    {
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL)
        return 1;
    return 0;
}

void decode_huff(node * root,string s)
{
    int len = s.length();
    node* r = root;
    int i = 0;
    for (i = 0 ; i < len; i++)
        {
            if(s[i] == '1')
                {                  
                    if(r != NULL)
                    {
                      r = r -> right;
                      if(is_leaf(r))
                        {
                            printf("%c", r-> data); 
                            r = root;
                            continue;
                        }
                    }
                    continue;
                        
           
                }
            else if (s[i] == '0')
                {
                    if(r != NULL)
                    {                         
                        r = r -> left;
                        if(is_leaf(r))
                        {
                            printf("%c", r-> data);  
                            r = root;
                            continue;
                        }
                        continue;
                    }

                }
         }
}
