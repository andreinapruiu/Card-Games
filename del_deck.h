// Copyright Andrei Napruiu 312CA 2022
#ifndef DEL_DECK_H_
#define DEL_DECK_H_

#include "main.h"

/*
 * Function that deletes the deck at the index "index" from the deck collection
*/
int del_deck(list_t *decks, int index);

/*
 * Function that deletes the card at "card_index" from the deck at "deck_index"
*/
void del_card(list_t *decks, int deck_index, int card_index);

#endif		// DEL_DECK_H_
