// Copyright Andrei Napruiu 312CA 2022
#ifndef DLL_IMPLEMENTATION_H_
#define DLL_IMPLEMENTATION_H_
#include "main.h"

/*
 * Function that needs to be called for allocation and initialization of a list
 * (Setting intial values for data in list structure)
 */
list_t*
dll_create();

/*
 * The function return a pointer to the nth node of the list.
 */
node_t*
dll_get_nth_node(list_t *list, unsigned int n);

/*
 * Function that add in the list, at the nth position, the new data/card.
 */
void
dll_add_nth_node(list_t *list, unsigned int n, const void *data,
				 unsigned int data_size);

/*
 * Function that deletes the nth node from a list given as parameter.
 */
node_t*
dll_remove_nth_node(list_t *list, unsigned int n);


/*
 * The function return the number of nodes existing in a list sent as parameter
 */
unsigned int
dll_get_size(list_t *list);


/*
 * The function frees everything in a list(all the nodes and the list itself).
 */
void
dll_free(list_t *pp_list);

/*
 * Function that prints all the nodes from a list. Used mostly for printing
 * the elements from a deck at SHOW_DECK and SHOW_ALL commands.
 */
void
dll_print_list(list_t *list);

/*
 * Function that return the merge of 2 lists(one element at a time
 * from each list)
 * Example: list1 -> 1 4 6 5 3
 * 			list2 -> 3 5 7 8 9 10
 * 			Result: 1 3 4 5 6 7 5 8 3 9 10
*/
list_t*
merge_lists(list_t *list1, list_t *list2);

#endif		// DLL_IMPLEMENTATION_H_
