#ifndef HEAD_H
#define HEAD_H

struct node
{
	int	data; 
	node *left, *right;
};

node *tree = NULL;

void print_tree(node *, int);
node *search(node **, int);
void add_element(int, node **);
void remove_element();
void view_tree();
void tree_array();

#endif
