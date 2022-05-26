#pragma once

#include "defs.h"

struct node
{
	T element;
	struct node *left, *right;
};

struct binary_tree
{
	struct node *root;
};

/*
	function prototypes
*/
struct binary_tree *init_binary_tree(struct binary_tree *t);
//void destroy_tree(struct node *root);
void uninit_binary_tree(struct binary_tree *t);
struct node *build_tree(T v, struct node *left_child, struct node *right_child);
struct node *empty_tree();
void pre_order_traversal(struct node *t, void *user, void(*f)(struct node *t, void *user));
int size(struct node *t);
int height(struct node *t);
int new_height(struct node *t);






