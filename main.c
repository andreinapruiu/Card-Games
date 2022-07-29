// Copyright Andrei Napruiu 312CA 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// All the brief explanations are in the header files
#include "main.h"  // all structures
#include "add_deck.h"  // functions that add something in the decks
#include "show_deck.h"  // functions that print something
#include "del_deck.h"  // functions that remove cards/decks from the decks
#include "play_deck.h"  // functions that change something in the decks
#include "exit.h"  // function that exits the program and frees
#include "dll_implementation.h"  // implementation for doubly linked list

commands_t change_command(char *command, int *parameters)
{
	char *p = strchr(command, '\n');
	char **input = malloc(MAXCOM * sizeof(char *));
	if (!input) {
		fprintf(stderr, "Error with the allocation\n");
		free(input);
		return NO;
	}

	char *tok = strtok(command, " ");
	int i = 0;

	if (p)
		*p = '\0';

	while (tok) {
		input[i] = tok;
		tok = strtok(NULL, " ");
		i++;
	}

	for (int j = 0; j < i - 1; j++)
		parameters[j] = atoi(input[j + 1]);

	if (strcmp(input[0], "ADD_DECK") == 0) {
		if (i == 2) {
			free(input);
			return ADD_DECK;
		}
	} else if (strcmp(input[0], "DEL_DECK") == 0) {
		if (i == 2) {
			free(input);
			return DEL_DECK;
		}
	} else if (strcmp(input[0], "DEL_CARD") == 0) {
		if (i == 3) {
			free(input);
			return DEL_CARD;
		}
	} else if (strcmp(input[0], "ADD_CARDS") == 0) {
		if (i == 3) {
			free(input);
			return ADD_CARDS;
		}
	} else if (strcmp(input[0], "DECK_NUMBER") == 0) {
		if (i == 1) {
			free(input);
			return DECK_NUMBER;
		}
	} else if (strcmp(input[0], "DECK_LEN") == 0) {
		if (i == 2) {
			free(input);
			return DECK_LEN;
		}
	} else if (strcmp(input[0], "SHUFFLE_DECK") == 0) {
		if (i == 2) {
			free(input);
			return SHUFFLE_DECK;
		}
	} else if (strcmp(input[0], "MERGE_DECKS") == 0) {
		if (i == 3) {
			free(input);
			return MERGE_DECKS;
		}
	} else if (strcmp(input[0], "SPLIT_DECK") == 0) {
		if (i == 3) {
			free(input);
			return SPLIT_DECK;
		}
	} else if (strcmp(input[0], "REVERSE_DECK") == 0) {
		if (i == 2) {
			free(input);
			return REVERSE_DECK;
		}
	} else if (strcmp(input[0], "SHOW_DECK") == 0) {
		if (i == 2) {
			free(input);
			return SHOW_DECK;
		}
	} else if (strcmp(input[0], "SHOW_ALL") == 0) {
		if (i == 1) {
			free(input);
			return SHOW_ALL;
		}
	} else if (strcmp(input[0], "SORT_DECK") == 0) {
		if (i == 2) {
			free(input);
			return SORT_DECK;
		}
	} else if (strcmp(input[0], "EXIT") == 0) {
		free(input);
		return -(-EXIT);
	}

	free(input);
	return NO;
}

int main(void)
{
	int *parameters = malloc(MAXPAR * sizeof(int));
	if (!parameters) {
		fprintf(stderr, "Error with the allocation\n");
		return 0;
	}

	char *command = malloc(COMSIZE * sizeof(char));
	if (!command) {
		fprintf(stderr, "Error with the allocation\n");
		free(parameters);
		return 0;
	}

	list_t *decks = dll_create();
	if (!decks) {
		fprintf(stderr, "Error with the allocation\n");
		free(parameters);
		free(command);
		return 0;
	}

	commands_t option = NO;

	while (option != EXIT) {
		fgets(command, COMSIZE, stdin);
		option = change_command(command, parameters);

		switch (option) {
		case ADD_DECK:
			add_deck(decks, parameters[0]);
			break;
		case DEL_DECK:
			if (del_deck(decks, parameters[0]))
				DECK_DELETED(parameters[0]);
			break;
		case DEL_CARD:
			del_card(decks, parameters[0], parameters[1]);
			break;
		case ADD_CARDS:
			add_cards(decks, parameters[0], parameters[1]);
			break;
		case DECK_NUMBER:
			deck_number(decks);
			break;
		case DECK_LEN:
			deck_len(decks, parameters[0]);
			break;
		case SHUFFLE_DECK:
			shuffle_deck(decks, parameters[0]);
			break;
		case MERGE_DECKS:
			merge_decks(decks, parameters[0], parameters[1]);
			break;
		case SPLIT_DECK:
			split_deck(decks, parameters[0], parameters[1]);
			break;
		case REVERSE_DECK:
			reverse_deck(decks, parameters[0]);
			break;
		case SHOW_DECK:
			show_deck(decks, parameters[0]);
			break;
		case SHOW_ALL:
			show_all(decks);
			break;
		case SORT_DECK:
			sort_deck(decks, parameters[0]);
			break;
		case EXIT:
			free_exit(decks);
			break;
		case NO:
			INVALID_COMMAND;
			break;
		default:
			break;
		}
	}

	free(parameters);
	free(command);

	return 0;
}
