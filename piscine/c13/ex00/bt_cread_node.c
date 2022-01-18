#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
	t_btree	btree;

	btree = malloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	btree.left = 0;
	btree.right = 0;
	btree.item = item;
	return (&btree);
}
