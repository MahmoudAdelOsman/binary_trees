#include "binary_trees.h"

levelorder_queue_t *momo_create_node(binary_tree_t *node);
void momo_free_queu(levelorder_queue_t *head);
void momo_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void momo_pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * momo_create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */

levelorder_queue_t *momo_create_node(binary_tree_t *node)
{
	levelorder_queue_t *x;

	x = malloc(sizeof(levelorder_queue_t));
	if (x == NULL)
		return (NULL);

	x->node = node;
	x->next = NULL;

	return (x);
}

/**
 * momo_free_queu - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */

void momo_free_queu(levelorder_queue_t *head)
{
	levelorder_queue_t *a;

	while (head != NULL)
	{
		a = head->next;
		free(head);
		head = a;
	}
}

/**
 * momo_push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 */

void momo_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *a;

	a = momo_create_node(node);
	if (a == NULL)
	{
		momo_free_queu(head);
		exit(1);
	}
	(*tail)->next = a;
	*tail = a;
}

/**
 * momo_pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */

void momo_pop(levelorder_queue_t **head)
{
	levelorder_queue_t *a;

	a = (*head)->next;
	free(*head);
	*head = a;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *xx1, *xx2;
	unsigned char z = 0;

	if (tree == NULL)
		return (0);

	xx1 = xx2 = momo_create_node((binary_tree_t *)tree);
	if (xx1 == NULL)
		exit(1);

	while (xx1 != NULL)
	{
		if (xx1->node->left != NULL)
		{
			if (z == 1)
			{
				momo_free_queu(xx1);
				return (0);
			}
			momo_push(xx1->node->left, xx1, &xx2);
		}
		else
			z = 1;
		if (xx1->node->right != NULL)
		{
			if (z == 1)
			{
				momo_free_queu(xx1);
				return (0);
			}
			momo_push(xx1->node->right, xx1, &xx2);
		}
		else
			z = 1;
		momo_pop(&xx1);
	}
	return (1);
}
