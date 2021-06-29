#pragma once
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

struct Stack
{
	struct TreeNode *t;
	struct Stack *link;
};

struct Stack *stack = NULL;

bool isEmpty(struct Stack *top)
{
	return top == NULL;
}

void push(struct TreeNode *treenode)
{
	struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
//	st->t = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	if (st == NULL)
	{
		printf("Stack Overflow \n");
		return;
	}

	st->t = treenode;
	st->link = stack;

	stack = st;
}

struct TreeNode* pop(struct Stack *top_ref)
{
	struct TreeNode *tnode;
	struct Stack *snode;

	if (isEmpty(top_ref))
	{
		printf("Stack Underflow \n");
		getchar();
		exit(0);
	}
	else
	{
		snode = stack;
		tnode = snode->t;
		stack = stack->link;
		free(snode);
		return tnode;
	}
}

/*
void disposeStack(struct Stack *st)
{
	if (st != NULL)
	{
		free(st->t);
		free(st);
	}
}
*/