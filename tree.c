#include "header.h"
node* new_node1(int data)
{
	node* new_node = (node *)malloc(sizeof(node));
	new_node ->data = data;
	new_node -> parent = NULL;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}

void preorder(node* root)
{
	if(root !=NULL)
	{
		printf("%d ", root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

void postorder(node* root)
{
	if(root !=NULL)
	{
		postorder(root -> left);
		postorder(root -> right);
		printf("%d ", root -> data);
	}
}
void inorder(node* root)
{
	if(root !=NULL)
	{
		inorder(root -> left);
		printf("%d ", root -> data);
		inorder(root -> right);
	}
}
node* insert(node* root, int data)
{
	node* new_node = new_node1(data);
	node* new_root = root;
	node* temp;
	if(root == NULL)
	{
		root = new_node;
		return root;
	}
	else 
	{
		while(new_root != NULL)
		{
			temp = new_root;
			if(new_root -> data > new_node -> data)
			{
				new_root = new_root -> left;
			}
			else if(new_root -> data < new_node -> data)
			{
				new_root = new_root -> right;
			}
		}		
		new_node -> parent = temp;
		if(new_node->data > temp -> data)
		{
			temp->right = new_node;
			return root;
		}
		temp -> left = new_node;
	}
	return root;
}

node* min(node* root)
{
	while(root-> left != NULL)
	{	
		root = root -> left;
	}
	return root;
}
node* inorder_successor(node* root)
{
	if(root -> right != NULL)
		return min(root->right);	
	while(root -> parent != NULL && root -> parent -> right == root)
		root = root -> parent;
	return root;
}
node *delete_node(node* root, int key)
{
	if(root == NULL) return NULL;
	if(key < root -> data)
	{
		root->left = delete_node(root->left, key);	
	}
	else if(key > root->data)
	{
		root -> right = delete_node(root->right, key);
	}
	else
	{
		if(root -> left == NULL)
		{
			node * temp = root -> right;
			free(root);
			return temp;
		}
		else if(root -> right == NULL)
		{
			node * temp = root -> left;
			free(root);
			return temp;
		}
		else
		{
			//Inorder successor
			node* temp = inorder_successor(root);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root;	
}
