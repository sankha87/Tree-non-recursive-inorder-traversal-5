// Iterative Inorder Traversal (Non-recursive)		https://www.youtube.com/watch?v=SiyEwLrPpyQ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Stack.h"
#include <time.h>

TreeNode* createTree(int num);
void inorder_recursive(TreeNode* root);
void inorder_non_recursive(TreeNode* root);

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n)
{
	// Base case for recursion
	if (i < n)
	{

		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = arr[i];
		temp->left = NULL;
		temp->right = NULL;
		root = temp;

		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);		// insert left child
																			//arr   = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
																			//index = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);		// insert right child
	}
	return root;
}

int main()
{
	int num;
	printf("Enter number of nodes : ");
	scanf("%d", &num);
	TreeNode *root = createTree(num);

	printf("Recursive Inorder : \n");
	inorder_recursive(root);

	printf("\n\nNon-Recursive Inorder : \n");
	inorder_non_recursive(root);
	_getch();
}

TreeNode* createTree(int num)
{
	if (num == 0)
		return NULL;
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));

	int* arr = (int*)malloc(num * sizeof(int));
	for (int i = 1; i <= num; i++)
		arr[i - 1] = i;
	// arr = 1,2,3,4...10
	root = insertLevelOrder(arr, root, 0, num);

	return root;
}

void inorder_recursive(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{
		inorder_recursive(root->left);
		printf("%d \t", root->data);
		inorder_recursive(root->right);
	}
}

void inorder_non_recursive(TreeNode* root)
{
	//	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	//	s->t = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	while (1)
	{
		while (root)
		{
			push(root);
			root = root->left;
		}

		if (isEmpty(stack))
			break;

		root = pop(stack);

		printf("%d \t", root->data);

		root = root->right;
	}
//	disposeStack(stack);
}