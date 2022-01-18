#include "ft_btree.h"

int btree_level_count(t_btree *root)
{
    if(!*root)
        return (0);
    if (btree_level_count(root->right) >= btree_level_count(root->left))
        return (1 + btree_level_count(root->right
));
    else
        return (1 + btree_level_count(root->left));

}
void level_order_traversal(t_btree* root, int level, int *first, void (*applyf)(void *item, int current_level, int is_first_elem))
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        applyf(root->item,level,*first);
        *first = 0;
    }
    else if (level > 1)
    {
        *first = 1;//?
        level_order_traversal(root->left, level-1,first, applyf);
        level_order_traversal(root->right, level-1,first, applyf);
    }


void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)
{
    int levels;
    int i;
    int first;
 
    if (root == NULL)
        return;
    i = 0;
    first = 1;
    levels = btree_level_count(root);
    while (++i < levels)
        level_order_traversal(root,i,&first,applyf);
}
