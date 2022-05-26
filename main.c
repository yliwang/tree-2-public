#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "tree.h"

int is_bst(struct binary_tree *tree);

void main()
{
	struct binary_tree t;
	init_binary_tree(&t);

	for (int i = 0; i < 100; i++) {
		add_item(&t, i);
	}

	if (is_bst(&t)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	uninit_binary_tree(&t);
}


#if 0
/*
tree:
a
/ \
b   c
\
d
*/
void main()
{
	struct binary_tree t;
	init_binary_tree(&t);

	t.root = build_tree('a', build_tree('b', empty_tree(), build_tree('d', empty_tree(), empty_tree())), build_tree('c', empty_tree(), empty_tree()));

	//destroy_tree( t.root );
	uninit_binary_tree(&t);

	/* another version */
	t.root = create_node('a');
	t.root->left = create_node('b');
	t.root->left->right = create_node('d');
	t.root->right = create_node('c');

	//destroy_tree( t.root );
	uninit_binary_tree(&t);
}
#endif