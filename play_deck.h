// Copyright Andrei Napruiu 312CA 2022
#ifndef PLAY_DECK_H_
#define PLAY_DECK_H_

#include "main.h"

/*
 * Function that shuffles the deck at "index". The shuffle represents splitting
 * a deck at the half point and putting the first half after the second one
 * Example: list -> 1 2 3 4 5
 * 			Result -> 3 4 5 1 2
*/
void shuffle_deck(list_t *decks, int index);

/*
 * Function that merges two decks given by their index.
 * Example: list1 -> 1 4 6 5 3
 * 			list2 -> 3 5 7 8 9 10
 * 			Result: 1 3 4 5 6 7 5 8 3 9 10
*/
void merge_decks(list_t *decks, int index1, int index2);

/*
 * Function that splits the deck "deck_index" at the card "split_index".
 * The second deck is added next to the first one.
 * Example: list -> 1 2 3 4 5, split_index = 2
 * 			Result: list1 -> 1 2
 * 					list2 -> 3 4 5
*/
void split_deck(list_t *decks, int deck_index, int split_index);

/*
 * Function that reverses the deck at "index". Simple as that.
 * Example: list -> 1 2 3 4 5
 * 			Result: 5 4 3 2 1
*/
void reverse_deck(list_t *decks, int index);

/*
 * Function that sorts the deck at "index" by value, than by symbol
 * Example: list -> 1C 2S 3D 4C 5C 2H 4D 1H
 * 			Result: 1H 1C 2H 2S 3D 4D 4C 5C
 * Note: D = Diamond
 * 		 H = Heart
 * 		 S = Spade
 * 		 C = Club
*/
void sort_deck(list_t *decks, int index);

#endif		// PLAY_DECK_H_
