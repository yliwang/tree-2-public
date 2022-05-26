#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#include "tree.h"


void is_bst_recursive(struct node *r, int *flag )
{
	assert(r != NULL);
}



int is_bst(struct binary_tree *tree)
{
	int flag = 0;

	assert(tree != NULL);
	assert(tree->root != NULL);

	is_bst_recursive(tree->root, &flag );

	return flag == 0;
}
