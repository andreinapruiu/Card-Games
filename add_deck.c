// Copyright Andrei Napruiu 312CA 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "add_deck.h"
#include "dll_implementation.h"

void add_deck(list_t *decks, int card_number)
{
	int good_cards = 0;

	list_t *cards = dll_create();
	if (!cards) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}

	data_t *new_card = calloc(1, sizeof(data_t));
	if (!new_card) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}
	memset(new_card->symbol, 0, MAX_SYMBOL_SIZE);
	char *line = calloc(COMSIZE, sizeof(char));

	while (good_cards < card_number) {
		fgets(line, COMSIZE, stdin);
		sscanf(line, "%d%s", &new_card->nr, new_card->symbol);

		if (new_card->nr >= 1 && new_card->nr <= 14)
			if (!strcmp(new_card->symbol, "HEART") ||
				!strcmp(new_card->symbol, "CLUB") ||
				!strcmp(new_card->symbol, "SPADE") ||
				!strcmp(new_card->symbol, "DIAMOND")) {
				good_cards++;
				dll_add_nth_node(cards, card_number, new_card, sizeof(data_t));
			} else {
				INVALID_CARD;
			}
		else
			INVALID_CARD;
	}

	dll_add_nth_node(decks, decks->size, cards, sizeof(list_t));
	DECK_ADDED(card_number);

	free(cards);
	free(new_card);
	free(line);
}

void add_cards(list_t *decks, int deck_index, int card_number)
{
	if ((unsigned int)deck_index >= decks->size || deck_index < 0) {
		DECK_INDEX_OUT_OF_BOUNDS;
		return;
	}

	node_t *curr = dll_get_nth_node(decks, deck_index);

	int good_cards = 0;
	int pos = card_number + ((list_t *)curr->data)->size;

	list_t *cards = dll_create();
	if (!cards) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}

	data_t *new_card = calloc(1, sizeof(data_t));
	if (!new_card) {
		fprintf(stderr, "Error with the allocation\n");
		return;
	}

	char *line = calloc(COMSIZE, sizeof(char));

	while (good_cards < card_number) {
		fgets(line, COMSIZE, stdin);
		sscanf(line, "%d%s", &new_card->nr, new_card->symbol);

		if (new_card->nr && new_card->nr >= 1 && new_card->nr <= 14)
			if (!strcmp(new_card->symbol, "HEART") ||
				!strcmp(new_card->symbol, "CLUB") ||
				!strcmp(new_card->symbol, "SPADE") ||
				!strcmp(new_card->symbol, "DIAMOND")) {
				good_cards++;
				dll_add_nth_node((list_t *)curr->data, pos, new_card, sizeof(data_t));
			} else {
				INVALID_CARD;
			}
		else
			INVALID_CARD;

		strcpy(line, "");
		new_card->nr = 0;
	}

	CARDS_ADDED(deck_index);

	free(cards);
	free(new_card);
	free(line);
}
