  /* C program to demonstrate Insert and
   delete operation in binary
   search tree*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}


struct node* insert(struct node* node, int key)
{
	// If the tree is empty, return a new node 
	if (node == NULL)
		return newNode(key);

	// Otherwise, search  the tree 
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	// return the node pointer 
	return node;
}

 
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	// loop down to find the leftmost leaf 
	while (current && current->left != NULL)
		current = current->left;

	return current;
}


struct node* deleteNode(struct node* root, int key)
{
	
	if (root == NULL)
		return root;

	
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	
	else {
		// node with only one child or no child
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children:
		// Get the inorder successor
		
		struct node* temp = minValueNode(root->right);

		// Copy the inorder
		// successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}


int main()
{
	int n,i,val,deval,ch;
	struct node* root = NULL;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	printf("Enter the nodes you want in the tree\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&val);
		root = insert(root ,val );
	}
	printf("Inorder traversal of the given tree \n");
	inorder(root);
	printf("Do you want to delete a value? Enter 1 for yes and 0 for No: ");
	scanf("%d",&ch);
	while(ch==1)
	{
		printf("Enter value you want to delete: ");
		scanf("%d",&deval);
		printf("\nDelete %d \n",deval);
		root = deleteNode(root,deval);
		printf("Inorder traversal of the tree after deletion \n");
		inorder(root);
		printf("Do you want to delete another value? Enter 1 for yes and 0 for No: ");
		scanf("%d",&ch);
    }
	return 0;
}

