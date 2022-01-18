#include "ft_btree.h"
int	btree_level_count(t_btree *root)
{
	if (!*root)
		return (0);
	if (btree_level_count(root->rigth) >= btree_level_count(root->left))
		return (1 + btree_level_count(root->rigth));
	else
		return (1 + btree_level_count(root->left));
}