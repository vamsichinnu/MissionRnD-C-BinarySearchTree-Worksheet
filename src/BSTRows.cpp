/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/


#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int get_height1(struct node *root){
	int leftheight, rightheight;
	if (root == NULL)
		return 0;
	else
	{
		leftheight = get_height1(root->left);
		rightheight = get_height1(root->right);
		if (leftheight >rightheight)
		{
			return leftheight + 1;
		}
		else
		{
			return rightheight + 1;
		}
	}
	return 0;
}
void adding(struct node *root, int i, int *output, int *j)
{
	int k;
	if (root==NULL)
	{
		return;
	}
	if (i == 1)
	{
		k = (*j)++;
		output[k] = root->data;
	}
	else
	{
			adding(root->right, i-1, output, j);
			adding(root->left, i-1, output, j);
	}
	
}
int* BSTRighttoLeftRows(struct node* root)
{
		int *output, i, height, j = 0;
		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node) * 1);
		temp = root;
		output = (int *)malloc(sizeof(int)* 100);
		if (root == NULL)
			return NULL;
		else
		{
			height = get_height1(temp);
			for (i = 1; i <=height; i++)
			{
				adding(root, i, output, &j);
			}
		}
		return output;
}