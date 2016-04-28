/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int get_height(struct node *root){
	int leftheight, rightheight;
	if (root == NULL)
		return 0;
	else
	{
		leftheight = get_height(root->left);
		rightheight = get_height(root->right);
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
int cal_sum(struct node *root, int *sum)
{
	if (root == NULL)
		return 0;
	else
	{
		cal_sum(root->left, sum);
		cal_sum(root->right, sum);
		*sum = *sum + root->data;
	}
	return *sum;
}
int get_left_subtree_sum(struct node *root){
	int sum = 0;
	if (root == NULL)
		return -1;
	else
		return cal_sum(root->left, &sum);
}

int get_right_subtree_sum(struct node *root){
	int sum = 0;
	if (root == NULL)
		return -1;
	else
		return cal_sum(root->right, &sum);
}


