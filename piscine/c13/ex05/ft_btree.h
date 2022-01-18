#ifndef FT_BTREE_H
# define FT_BTREE_H
struct s_btree{
	struct s_btree	*right;
	struct s_btree	*left;
	void			*item;
}t_btree;
#endif