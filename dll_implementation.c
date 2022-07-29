// Copyright Andrei Napruiu 312CA 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 64

#include "main.h"

list_t*
dll_create()
{
	list_t *list = malloc(sizeof(list_t));
	if (!list) {
		fprintf(stderr, "Error with the allocation\n");
		return NULL;
	}

	list->size = 0;
	list->head = NULL;

	return list;
}

node_t*
dll_get_nth_node(list_t* list, unsigned int n)
{
	if (!list)
		return NULL;

	if (!list->head)
		return NULL;

	if (n >= list->size)
		n = list->size;

	node_t *curr = list->head;

	for (unsigned int i = 0; i < n; i++)
		curr = curr->next;

	return curr;
}

void
dll_add_nth_node(list_t* list, unsigned int n, const void* data,
				 unsigned int data_size)
{
	if(!list)
		return;

	node_t *new = malloc(sizeof(node_t));
	if (!new) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}

	new->data = malloc(data_size);
	if (!new->data) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}

	memcpy(new->data, data, data_size);

	if (n >= list->size)
		n = list->size;

	node_t *head = list->head;

	if (!n) {
		if (!list->head) {
			new->prev = NULL;
			new->next = NULL;
			list->head = new;
		} else {
			new->next = head;
			new->prev = NULL;
			head->prev = new;
			list->head = new;
		}
	} else if (n < list->size) {
		node_t *curr = list->head;
		for (unsigned int i = 0; i < n - 1; i++)
			curr = curr->next;

		new->next = curr->next;
		new->prev = curr;
		curr->next->prev = new;
		curr->next = new;
	} else {
		node_t *curr = list->head;
		for (unsigned int i = 0; i < n - 1; i++)
			curr = curr->next;

		new->next = NULL;
		new->prev = curr;
		curr->next = new;
	}

	list->size++;
}

node_t*
dll_remove_nth_node(list_t* list, unsigned int n)
{
	if(!list)
		return NULL;

	if (!list->head)
		return NULL;

	if (n >= list->size - 1)
		n = list->size - 1;

	node_t *head = list->head;

	node_t *del = list->head;
	if (!n) {
		if (list->size != 1) {
			head = head->next;
			head->prev = NULL;
			list->head = head;
		} else {
			list->head = NULL;
		}
	} else if (n < list->size - 1){
		node_t *curr = list->head;
		for (unsigned int i = 0; i < n - 1; i++)
			curr = curr->next;

		del = curr->next;

		curr->next = curr->next->next;
		curr->next->prev = curr;
	} else {
		node_t *curr = list->head;
		for (unsigned int i = 0; i < n - 1; i++)
			curr = curr->next;

		del = curr->next;

		curr->next = NULL;
	}

	list->size--;
	return del;
}

unsigned int
dll_get_size(list_t* list)
{
	if(!list)
		return 0;

	if (!list->head)
		return 0;

	return list->size;
}

void
dll_free(list_t* pp_list)
{
	node_t *curr = pp_list->head;
	int size = pp_list->size;

	node_t *del = curr;
	for (int i = 0; i < size; i++) {
		free(curr->data);
		curr = curr->next;
		free(del);
		del = curr;
	}

	free(pp_list);
}

void
dll_print_list(list_t* list)
{
	int size = list->size;
	node_t *curr = list->head;

	for (int i = 0; i < size; i++) {
		printf("\t%d %s\n", ((data_t *)curr->data)->nr,
			   ((data_t *)curr->data)->symbol);
		curr = curr->next;
	}
}

list_t*
merge_lists(list_t* list1, list_t* list2)
{
	int n = list1->size;
	int m = list2->size;

	node_t *curr1 = list1->head;
	node_t *curr2 = list2->head;

	list_t *merged = dll_create();

	int i = 0, j = 0;
	int size = 0;


	while (i < n && j < m) {
		dll_add_nth_node(merged, size++, curr1->data, sizeof(data_t));
		dll_add_nth_node(merged, size++, curr2->data, sizeof(data_t));

		curr1 = curr1->next;
		curr2 = curr2->next;
		i++;
		j++;
	}

	while (i < n) {
		dll_add_nth_node(merged, size++, curr1->data, sizeof(data_t));

		curr1 = curr1->next;
		i++;
	}

	while (j < m) {
		dll_add_nth_node(merged, size++, curr2->data, sizeof(data_t));

		curr2 = curr2->next;
		j++;
	}

	return merged;
}
