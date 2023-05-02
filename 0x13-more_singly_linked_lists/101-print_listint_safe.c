#include "lists.h"

/**
 * free_listp - frees a linked list
 * @head: head of a list.
 *
 * Return: no return.
 */
void free_listp(listp_t **head)
{
	listp_t *temp;
	listp_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * print_listint_safe - prints a linked list.
 * @head: head of a list.
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t mnodes = 0;
	listp_t *hptr, *nw, *add;

	hptr = NULL;
	while (head != NULL)
	{
		nw = malloc(sizeof(listp_t));

		if (nw == NULL)
			exit(98);

		nw->p = (void *)head;
		nw->next = hptr;
		hptr = nw;

		add = hptr;

		while (add->next != NULL)
		{
			add = add->next;
			if (head == add->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&hptr);
				return (mnodes);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		mnodes++;
	}

	free_listp(&hptr);
	return (mnodes);
}
