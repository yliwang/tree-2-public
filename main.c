#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "tree.h"

int is_bst(struct binary_tree *tree);

void main()
{
	struct binary_tree t;
	init_binary_tree(&t);

	uninit_binary_tree(&t);
}


