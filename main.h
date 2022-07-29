// Copyright Andrei Napruiu 312CA 2022
#ifndef MAIN_H_
#define MAIN_H_

#define COMSIZE 256  // size for commands
#define MAXPAR 3  // max number of parameters + 1 for memory leaks
#define MAXCOM 5
#define MAX_SYMBOL_SIZE 10  // max size of a string representing a symbol
						   // (HEART, DIAMOND, SPADE, CLUB)

/*
 * Error messages as given in the homework
*/
#define DECK_INDEX_OUT_OF_BOUNDS \
(printf("The provided index is out of bounds for the deck list.\n"))
#define CARD_INDEX_OUT_OF_BOUNDS(index) \
(printf("The provided index is out of bounds for deck %d.\n", index))
#define INVALID_CARD \
(printf("The provided card is not a valid one.\n"))
#define INVALID_COMMAND \
(printf("Invalid command. Please try again.\n"))

/*
 * Succesful operations messages as given in the homework
*/
#define DECK_ADDED(number) \
(printf("The deck was successfully created with %d cards.\n", number))
#define DECK_DELETED(index) \
(printf("The deck %d was successfully deleted.\n", index))
#define CARD_DELETED(index) \
(printf("The card was successfully deleted from deck %d.\n", index))
#define CARDS_ADDED(index) \
(printf("The cards were successfully added to deck %d.\n", index))
#define DECK_NUMBER(number) \
(printf("The number of decks is %d.\n", number))
#define DECK_LEN(index, number) \
(printf("The length of deck %d is %d.\n", index, number))
#define DECK_SHUFFLED(index) \
(printf("The deck %d was successfully shuffled.\n", index))
#define DECKS_MERGED(index1, index2) \
(printf("The deck %d and the deck %d were successfully merged.\n", \
index1, index2))
#define DECK_SPLIT(index1, index2) \
(printf("The deck %d was successfully split by index %d.\n", \
index1, index2))
#define DECK_REVERSED(index) \
(printf("The deck %d was successfully reversed.\n", index))
#define DECK_SORTED(index) \
(printf("The deck %d was successfully sorted.\n", index))

/*
 * Structure for a node in the list. The data pointer can be used for cards
 * and for lists.
*/
typedef struct node_t node_t;
struct node_t {
	void *data;
	node_t *prev;
	node_t *next;
};

/*
 * Structure for the list having the first node saved inside for using the list
 * later in the rest of the program
*/
typedef struct list_t list_t;
struct list_t {
	node_t *head;
	unsigned int size;
};

/*
 * Structure for a card having the number and the symbol(static values)
*/
typedef struct data_t data_t;
struct data_t {
	unsigned int nr;
	char symbol[MAX_SYMBOL_SIZE];  // if dynamic allocated => problems
};

/*
 * Enumeration type for the commands for easier use and return
 * later in the functions
*/
typedef enum commands_t commands_t;
typedef enum commands_t {
	NO,
	ADD_DECK,
	DEL_DECK,
	DEL_CARD,
	ADD_CARDS,
	DECK_NUMBER,
	DECK_LEN,
	SHUFFLE_DECK,
	MERGE_DECKS,
	SPLIT_DECK,
	REVERSE_DECK,
	SHOW_DECK,
	SHOW_ALL,
	SORT_DECK,
	EXIT
} commands_t;

/*
 * Function that uses the command variable(saves the entire line
 * with the command) and returns the command as an enum type. Also, in the
 * parameters variable we save the parameters used for the command.
*/
commands_t change_command(char *command, int *parameters);

#endif		// MAIN_H_
