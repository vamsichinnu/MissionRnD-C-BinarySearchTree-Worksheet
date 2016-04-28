/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
node * bst(int *arr, int min, int max)
{
	int mid;
	struct node *temp;
	mid = (min + max) / 2;
	if (min <= max)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = arr[mid];
		temp->left = bst(arr, min, mid - 1);
		temp->right = bst(arr, mid + 1, max);
		return temp;
	}
	return NULL;
}
struct node * convert_array_to_bst(int *arr, int len){
	struct node *root = NULL, *temp1;
	root = (struct node *)malloc(sizeof(struct node) * 1);
	temp1 = (struct node *)malloc(sizeof(struct node) * 1);
	if (len >0&&arr!=NULL)
	{
		root = bst(arr, 0, len - 1);

		return root;
	}
	else
	{
		return NULL;
	}
}
