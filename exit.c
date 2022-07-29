// Copyright Andrei Napruiu 312CA 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "exit.h"
#include "dll_implementation.h"
#include "del_deck.h"

void free_exit(list_t *decks)
{
	node_t *curr = decks->head;
	int size = decks->size;

	node_t *del = curr;
	for (int i = 0; i < size; i++) {
		dll_free((list_t *)curr->data);
		curr = curr->next;
		free(del);
		del = curr;
	}

	free(decks);
}
