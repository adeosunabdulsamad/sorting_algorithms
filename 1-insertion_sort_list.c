#include "sort.h"

/**
 * listint_len - Counts the number of elements in a linked list
 * @list: Pointer to the head of the list
 * Return: Number of elements in the list
 */
size_t listint_len(const listint_t *list)
{
    size_t count = 0;

    while (list)
    {
        count++;
        list = list->next;
    }

    return (count);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    size_t n, j;
    size_t length = listint_len(*list);
    listint_t *current, *prev_node;

    for (n = 1; n < length; n++)
    {
        current = (*list)->next;
        for (j = n; j > 0; j--)
        {
            prev_node = current->prev;
            if (current && prev_node && current->n < prev_node->n)
            {
                swap(&prev_node, &current);
                if (prev_node->prev == NULL)
                    *list = prev_node;
                print_list(*list);
            }
            else
            {
                break;
            }
            current = prev_node;
        }
    }
}

/**
 * swap - Swaps the positions of two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap(listint_t **a, listint_t **b)
{
    listint_t *temp_next, *temp_prev;

    temp_next = (*a)->next;
    temp_prev = (*b)->prev;

    (*a)->next = (*b)->next;
    if ((*b)->next)
        (*b)->next->prev = (*a);
    (*a)->prev = temp_prev;
    if (temp_prev)
        temp_prev->next = (*a);

    (*b)->prev = (*a)->prev;
    if ((*a)->prev)
        (*a)->prev->next = (*b);
    (*b)->next = temp_next;
    if (temp_next)
        temp_next->prev = (*b);
}
