#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *k, *xx;

	if (tree != NULL)
	{
		k = *tree;

		if (k == NULL)
		{
			xx = binary_tree_node(k, value);
			if (xx == NULL)
				return (NULL);
			return (*tree = xx);
		}

		if (value < k->n) /* insert in left subtree */
		{
			if (k->left != NULL)
				return (bst_insert(&k->left, value));

			xx = binary_tree_node(k, value);
			if (xx == NULL)
				return (NULL);
			return (k->left = xx);
		}
		if (value > k->n) /* insert in right subtree */
		{
			if (k->right != NULL)
				return (bst_insert(&k->right, value));

			xx = binary_tree_node(k, value);
			if (xx == NULL)
				return (NULL);
			return (k->right = xx);
		}
	}
	return (NULL);
}
