// Copyright Andrei Napruiu 312CA 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "dll_implementation.h"

int del_deck(list_t *decks, int index)
{
	if ((unsigned int)index >= decks->size || index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return 0;
	}

	node_t *del = dll_remove_nth_node(decks, (unsigned int)index);
	dll_free(((list_t *)del->data));
	free(del);

	return 1;
}

void del_card(list_t *decks, int deck_index, int card_index)
{
	if ((unsigned int)deck_index >= decks->size || deck_index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr = dll_get_nth_node(decks, deck_index);

	if ((unsigned int)card_index >= ((list_t *)curr->data)->size ||
		card_index < 0) {
		CARD_INDEX_OUT_OF_BOUNDS(deck_index);
		return;
	}


	node_t *del = dll_remove_nth_node(curr->data, (unsigned int)card_index);
	free(del->data);
	free(del);

	if (((list_t *)curr->data)->size == 0)
		del_deck(decks, deck_index);

	CARD_DELETED(deck_index);
}
