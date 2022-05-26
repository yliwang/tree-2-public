#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "tree.h"

struct binary_tree *init_binary_tree( struct binary_tree *t )
{
	t->root = NULL;

	return t;
}

void destroy_tree( struct node *root )
{
	assert( root != NULL );

	if( root->left ) {
		destroy_tree( root->left );
	} 
	
	if( root->right ) {
		destroy_tree( root->right );
	}

	free( root );
}


void uninit_binary_tree( struct binary_tree *t )
{
	assert( t != NULL );

	if( t->root ) destroy_tree( t->root );

	t->root = NULL;
}



struct node *create_node( T v )
{
	struct node *p = (struct node *)malloc( sizeof(struct node) );
	
	p->element = v;
	p->left = NULL;
	p->right = NULL;

	return p;
}

struct node *build_tree( T v, struct node *left_child, struct node *right_child )
{
	struct node *p = create_node( v );

	p->left = left_child;
	p->right = right_child;

	return p;
}

struct node *empty_tree()
{
	return NULL;
}

 
void pre_order_traversal( struct node *t, void *user, void (*f)( struct node *t, void *user) )
{
	assert( t != NULL );
	f( t, user );  /* visit t */

	/* visit t->left, only when it exists */
	if( t->left ) {
		pre_order_traversal( t->left, user, f );
	}

	/* visit t->right, only when it exists */
	if( t->right ) {
		pre_order_traversal( t->right, user, f );
	}
}

void print_node( struct node *t, void *user ) /* user is ignored */
{
	printf( "%c, ", t->element );
}

#if 0
void count_node( struct node *t, void *user )
{
	int *p = (int *)user;

	if( t->left != NULL ) p[0] += 0x1<<16;
	if( t->right != NULL ) p[0] += 1;
}
#else
void count_node(struct node *t, void *user)
{
	int temp = *(int *)user;
	temp++;
	*(int *)user = temp;
}
#endif

int size( struct node *t )
{
	int num_nodes = 0;
	
	if( t == NULL ) return 0;

//	pre_order_traversal( t, 0, &num_nodes, count_node ); // this causes error
	pre_order_traversal(t, &num_nodes, count_node); // this causes error

	return num_nodes;
}


#if 1
int height( struct node *t )
{
	int lh, rh;
	lh = rh = 0;
	assert( t != NULL );
	if( t->left == NULL && t->right == NULL ) return 0;

	if( t->left != NULL ) lh = height( t->left ) + 1;
	if( t->right != NULL ) rh = height( t->right ) + 1;

	if( lh > rh ) return lh;
	return rh;
}
#else
int height( struct node *t )
{
	int lh, rh;
	int levels = 0;

	assert( t != NULL );

	pre_order_traversal( t, &levels, count_node );

	lh = levels >> 16;
	rh = levels & 0xffff;

	if( lh > rh ) return lh;
	return rh;
}
#endif

struct cpath_info
{
	int h;
	int maxh;
};

void sum_node(struct node *t, void *user)
{
	struct cpath_info *p = (struct cpath_info *)user;

	if (t == NULL) return;

	if (t->left == NULL && t->right == NULL) {
		if (p->h > p->maxh) p->maxh = p->h;
	}
	else {
		p->h += 1;
	}
}

int new_height(struct node *t) 
{
	struct cpath_info pi;

	pi.h = 0;
	pi.maxh = 0;

	assert(t != NULL);

	pre_order_traversal(t, &pi, sum_node); // this causes error

	printf("%d\n", pi.maxh);
}




