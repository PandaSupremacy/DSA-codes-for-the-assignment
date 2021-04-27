//program to create a binary search  tree
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node
{
    int value;
    struct node *left;
    struct node *right;
}*root= NULL,*temp=NULL,*t=NULL;
void assign(struct node *t)
{
    if ((temp->value > t->value) && (t->right != NULL))      
        assign(t->right);
    else if ((temp->value > t->value) && (t->right == NULL))
        t->right = temp;
    else if ((temp->value < t->value) && (t->left != NULL))    
        assign(t->left);
    else if ((temp->value < t->value) && (t->left == NULL))
        t->left = temp; 
}
insert(data)
{
	temp = (struct node *)malloc(sizeof(struct node));
    temp->value = data;
    temp->left = temp ->right = NULL;
    if (root == NULL) 
        root = temp;
    else 
        assign(root);
        
        
}

void display(struct node *t)
{
	if (root == NULL)
    {
        printf("No elements");
    }
    if (t->left != NULL)    
    	display(t->left);
    printf("%d -> ", t->value);
    if (t->right != NULL)    
        display(t->right);
}
void main()
{
	int ch,data,n,i;
	printf("Enter number of values you want to be entered in the tree\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	printf("Enter the data you want to insert in the binary tree\n");
	scanf("%d",&data);
	insert(data);
    } 
    
    display(root);
}

