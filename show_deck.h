// Copyright Andrei Napruiu 312CA 2022
#ifndef SHOW_DECK_H_
#define SHOW_DECK_H_

#include "main.h"

/*
 * Function that prints all the cards from the deck at the index "index"
*/
void show_deck(list_t *decks, int index);

/*
 * Function that prints all the decks with all the nodes
*/
void show_all(list_t *decks);

/*
 * Function that prints the decks number from the deck collection
*/
void deck_number(list_t *decks);

/*
 * Function that prints the size of a deck(the number of cards)
*/
void deck_len(list_t *decks, int index);

#endif		// SHOW_DECK_H_
