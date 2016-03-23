#include "header.h"

int main()
{
	node* root = NULL;
 	root = insert(root, 50);	
 	root = insert(root, 30);	
 	root = insert(root, 20);	
 	root = insert(root, 40);	
 	root = insert(root, 70);	
 	root = insert(root, 60);	
 	root = insert(root, 80);	
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	node* successor = inorder_successor(root);
	root = delete_node(root, 20);	
	root = delete_node(root, 30);	
	root = delete_node(root, 50);	
	inorder(root);
return 0;
}
