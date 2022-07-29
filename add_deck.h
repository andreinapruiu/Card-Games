// Copyright Andrei Napruiu 312CA 2022
#ifndef ADD_DECK_H_
#define ADD_DECK_H_

#include "main.h"

/*
 * Function that adds in the deck collection card_number cards given
 * by the user.
*/
void add_deck(list_t *decks, int card_number);

/*
 * Function that adds card_number cards in the deck_index deck. All the cards
 * are given by the user.
*/
void add_cards(list_t *decks, int deck_index, int card_number);

#endif		// ADD_DECK_H_
