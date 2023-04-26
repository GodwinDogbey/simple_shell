#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: pointing to the address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *newhead;

	if (!head)
		return (NULL);
	newhead = malloc(sizeof(list_t));
	if (!newhead)
		return (NULL);
	_memset((void *)newhead, 0, sizeof(list_t));
	newhead->num = num;
	if (str)
	{
		newhead->str = _strdup(str);
		if (!newhead->str)
		{
			free(newhead);
			return (NULL);
		}
	}
	newhead->next = *head;
	*head = newhead;
	return (newhead);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: poniting to the address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *newnode, *node;

	if (!head)
		return (NULL);

	node = *head;
	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);
	_memset((void *)newnode, 0, sizeof(list_t));
	newnode->num = num;
	if (str)
	{
		newnode->str = _strdup(str);
		if (!newnode->str)
		{
			free(newnode);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = newnode;
	}
	else
		*head = newnode;
	return (newnode);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointint the to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: pointint to the address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: pointing to the address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *nextnode, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		nextnode = node->next;
		free(node->str);
		free(node);
		node = nextnode;
	}
	*head_ptr = NULL;
}
