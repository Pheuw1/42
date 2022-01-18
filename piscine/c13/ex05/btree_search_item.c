#include "ft_btree.h"
void	*btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	if (!*root)
		return (NULL);
	if (root->left)
		btree_search_item(root->left, data_ref, cmpf);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	applyf(root->item);
	if (root->right)
		btree_search_item(root->rigth, data_ref, cmpf);
}
