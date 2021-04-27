#include<stdlib.h>
#include<stdio.h>

struct tree {
int data;
struct tree * right, * left;
};
typedef struct tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void preorder(node * tree)
{
    if (tree)
    {
        printf("%d ",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }

}

void inorder(node * tree)
{
    if (tree)
    {
        inorder(tree->left);
        printf("%d ",tree->data);
        inorder(tree->right);
    }
}

void postorder(node * tree)
{
    if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->data);
    }
}




void main()
{
    node *root;
      
    root = NULL;
    int n,val;
    printf("How many values do you wish to add in your tree?: ");
    scanf("%d",&n);
    printf("Enter their values\n");
    while (n>0) {
      scanf("%d",&val);
      insert(&root, val);
      n--;
    }

    printf("\nPre Order \n");
    preorder(root);

    printf("\nIn Order\n");
    inorder(root);

    printf("\nPost Order\n");
    postorder(root);

}
