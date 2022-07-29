// Copyright Andrei Napruiu 312CA 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "show_deck.h"
#include "dll_implementation.h"

void show_deck(list_t *decks, int index)
{
	if ((unsigned int)index >= decks->size || index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr = dll_get_nth_node(decks, index);

	printf("Deck %d:\n", index);

	dll_print_list(curr->data);
}

void show_all(list_t *decks)
{
	for (unsigned int i = 0; i < decks->size; i++)
		show_deck(decks, i);
}

void deck_number(list_t *decks)
{
	int nr = decks->size;

	DECK_NUMBER(nr);
}

void deck_len(list_t *decks, int index)
{
	if ((unsigned int)index >= decks->size || index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr = dll_get_nth_node(decks, index);

	int nr = ((list_t *)curr->data)->size;

	DECK_LEN(index, nr);
}
