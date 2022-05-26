#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#include "tree.h"


void is_bst_recursive(struct node *r, int *flag )
{
	assert(r != NULL);
	T a, b, c;

	if (*flag) return;

	if (r->left && r->right ) {
		a = r->left->element;
		b = r->element;
		c = r->right->element;
		if( a > b || c > b ) {
			*flag += 1;
			return; /* not need to check any more*/
		}
	}
	
	if (r->left) {
		a = r->left->element;
		b = r->element;
		if (a > b) {
			*flag += 1;
			return;
		}
	}
	
	if (r->right) {
		b = r->element;
		c = r->right->element;
		if (b > c) {
			*flag += 1;
			return;
		}
	}

	if (r->left) is_bst_recursive(r->left, flag);
	if (r->right) is_bst_recursive(r->right, flag);
}



int is_bst(struct binary_tree *tree)
{
	int flag = 0;

	assert(tree != NULL);
	assert(tree->root != NULL);

	is_bst_recursive(tree->root, &flag );

	return flag == 0;
}