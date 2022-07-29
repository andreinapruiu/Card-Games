// Copyright Andrei Napruiu 312CA 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "del_deck.h"
#include "dll_implementation.h"

void shuffle_deck(list_t *decks, int index)
{
	if ((unsigned int)index >= decks->size || index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr = dll_get_nth_node(decks, index);
	int size = ((list_t *)curr->data)->size;

	for (int i = 0; i < size / 2; i++) {
		node_t *move = dll_get_nth_node(((list_t *)curr->data), 0);
		dll_add_nth_node((list_t *)curr->data, size, move->data, sizeof(data_t));

		node_t *del = dll_remove_nth_node((list_t *)curr->data, 0);
		free(del->data);
		free(del);
	}

	DECK_SHUFFLED(index);
}

void merge_decks(list_t *decks, int index1, int index2)
{
	if ((unsigned int)index1 >= decks->size || index1 < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	if ((unsigned int)index2 >= decks->size || index2 < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr1 = dll_get_nth_node(decks, index1);
	node_t *curr2 = dll_get_nth_node(decks, index2);

	list_t *merged = merge_lists((list_t *)curr1->data, (list_t *)curr2->data);

	dll_add_nth_node(decks, decks->size, merged, sizeof(list_t));

	if (index1 > index2) {
		del_deck(decks, index1);
		del_deck(decks, index2);
	} else {
		del_deck(decks, index2);
		del_deck(decks, index1);
	}

	DECKS_MERGED(index1, index2);

	free(merged);
}

void split_deck(list_t *decks, int deck_index, int split_index)
{
	if ((unsigned int)deck_index >= decks->size || deck_index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr = dll_get_nth_node(decks, deck_index);
	int size = ((list_t *)curr->data)->size;

	if ((unsigned int)split_index >= ((list_t *)curr->data)->size ||
		split_index < 0) {
		CARD_INDEX_OUT_OF_BOUNDS(deck_index);
		return;
	}

	list_t *cards = dll_create();
	if (!cards) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}

	if (split_index) {
		node_t *curr_card = dll_get_nth_node((list_t *)curr->data, split_index);

		for (int i = split_index; i < size; i++) {
			dll_add_nth_node(cards, size, curr_card->data, sizeof(data_t));

			curr_card = curr_card->next;

			node_t *del = dll_remove_nth_node((list_t *)curr->data,
											  split_index);
			free(del->data);
			free(del);
		}

		dll_add_nth_node(decks, deck_index + 1, cards, sizeof(list_t));
	}

	DECK_SPLIT(deck_index, split_index);
	free(cards);
}

void reverse_deck(list_t *decks, int index)
{
	if ((unsigned int)index >= decks->size || index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr = dll_get_nth_node(decks, index);
	int size = ((list_t *)curr->data)->size;

	node_t *last_card = dll_get_nth_node((list_t *)curr->data, size - 1);

	list_t *cards = dll_create();
	if (!cards) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}

	for (int i = 0; i < size; i++) {
		dll_add_nth_node(cards, size, (data_t *)last_card->data, sizeof(data_t));
		last_card = last_card->prev;
	}

	del_deck(decks, index);

	dll_add_nth_node(decks, index, cards, sizeof(list_t));

	free(cards);

	DECK_REVERSED(index);
}

void swap_cards(node_t *card1, node_t *card2)
{
	int aux_nr = ((data_t *)card1->data)->nr;
	((data_t *)card1->data)->nr = ((data_t *)card2->data)->nr;
	((data_t *)card2->data)->nr = aux_nr;

	char *aux_str = malloc(MAX_SYMBOL_SIZE * sizeof(char));
	strcpy(aux_str, ((data_t *)card1->data)->symbol);
	strcpy(((data_t *)card1->data)->symbol, ((data_t *)card2->data)->symbol);
	strcpy(((data_t *)card2->data)->symbol, aux_str);

	free(aux_str);
}

void sort_deck(list_t *decks, int index)
{
	if ((unsigned int)index >= decks->size || index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr_deck = dll_get_nth_node(decks, index);
	int size = ((list_t *)curr_deck->data)->size;

	node_t *curr_i = ((list_t *)curr_deck->data)->head;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			node_t *curr_j = dll_get_nth_node((list_t *)curr_deck->data, j);

			if (((data_t *)curr_i->data)->nr > ((data_t *)curr_j->data)->nr) {
				swap_cards(curr_i, curr_j);
			} else if (((data_t *)curr_i->data)->nr ==
					   ((data_t *)curr_j->data)->nr) {
				int sym1 = 0, sym2 = 0;

				if (!strcmp(((data_t *)curr_i->data)->symbol, "HEART"))
					sym1 = 1;
				if (!strcmp(((data_t *)curr_i->data)->symbol, "SPADE"))
					sym1 = 2;
				if (!strcmp(((data_t *)curr_i->data)->symbol, "DIAMOND"))
					sym1 = 3;
				if (!strcmp(((data_t *)curr_i->data)->symbol, "CLUB"))
					sym1 = 4;

				if (!strcmp(((data_t *)curr_j->data)->symbol, "HEART"))
					sym2 = 1;
				if (!strcmp(((data_t *)curr_j->data)->symbol, "SPADE"))
					sym2 = 2;
				if (!strcmp(((data_t *)curr_j->data)->symbol, "DIAMOND"))
					sym2 = 3;
				if (!strcmp(((data_t *)curr_j->data)->symbol, "CLUB"))
					sym2 = 4;

				if (sym1 > sym2)
					swap_cards(curr_i, curr_j);
			}
		}
		curr_i = curr_i->next;
	}

	DECK_SORTED(index);
}
