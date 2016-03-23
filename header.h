#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node 
{
	int data;
	struct node *parent;
	struct node *left;
	struct node *right;
}node;

extern node* new_node1(int data);
extern void preorder(node* root);
extern void postorder(node* root);
extern void inorder(node* root);
extern node* insert(node*root,  int data);
extern node* min(node* root);
extern node* inorder_successor(node* root);
extern node* delete_node(node* root, int data);
