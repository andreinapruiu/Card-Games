&copy; 2022 Andrei Napruiu (napruiuandrei@gmail.com)

# Now you see me - Homework 1

# Contents:
1. [Short Description](#description)
2. [Commands](#commands)
3. [How to run it](#how-to-run-it)
4. [How to check it](#how-to-check-it)

## Description:

* The theme kind of recreates the "Now you see me" cards game. It has some functions that simulates how a human can play with multiple decks of cards, such as shuffle, delete, add cards, sort etc. It feels really magical.

* The decks are added to a list, every deck being already a list and by using simple commands(such as SHOW_ALL or MERGE_DECKS) the user can simulate the use of real life cards inside the program. The entire program is dinamicly allocated so no worries about memory leaks.

* I think the code is easy to read and also understand, most of the commands being already named very specific. Only the 'commands function' in the main file is a little hard to digest. Basically, the function uses a line(which contains the command given by the user) to split it into the real command(SHOW_ALL etc.) and parameters(deck_index, card_index etc.). All of this is done for later use as it can be seen in the main function where the commands given by the user are compared (in a switch) with the possible instructions for the decks.
<br>Also, in the main.c file, where are all the includes it is specified that every file has multiple function in it(very specific like show_deck.h has all the functions that print something)

* Other details about the homework can be seen in the [html](https://github.com/andreinapruiu/Card-Games/blob/c70fcb434d905684f31385aeaa01ac9e367fcf68/Tema%201%20-%20Now%20You%20See%20Me%20%5BCS%20Open%20CourseWare%5D.html) file attached in the repo.

# Commands
Below is the list of every command (in some cases explained), its input and its output.

> Every command is set to retunr an allocation error if something went wrong with the memory allocation.

## ADD_DECK \<number_of_cards>
**(loading of a deck of cards in memory)**

1. Input:
	- the number of cards to be added in the deck when saving it
	- the cards in the next format:
		```
		1 HEART
		2 CLUB
		3 SPADE
		4 DIAMOND
		5 CLUB
		...
		14 HEART
		```
	- it will read cards from the user until the number of cards is reached, so if we have this:
		```
		ADD_DECK 2
		1 HEART
		2 CLUBISSIMO
		4 DIMONDISIMO
		5 CLUB
		```
		the program will save the deck containing 1 HEART and 5 CLUB.
3. Output: 
	- if everything worked just fine, "The deck was successfully created with \<number_of_cards> cards.\n"
	- else it will show a specific message so that the user knows what
didn't work ("The provided card is not a valid one.\n")


## DEL_DECK \<deck_index>
**(deleting a given deck from the lsit)**

1. Input:
	- deck_index - self explanatory(the number of the deck we want to delete from the list)
3. Output:
	- if everything worked just fine,
"The deck \<deck_index> was successfully deleted.\n"
	- else it will show
a specific message so that the user knows what
didn't work ("The provided index is out of bounds for the deck list.\n")


## DEL_CARD \<deck_index> \<card_index>
**(deletes a specific card from a given deck)**

1. Input:
	- deck_index
	- card_index
3. Output:
	- if everything worked just fine, "The card was successfully deleted from deck \<deck_index>.\n".
	- else it will show a specific message so that the
user knows what didn't work
("The provided index is out of bounds for the deck list.\n" or "The provided index is out of bounds for deck \<deck_index>.\n")
3. Mention: if the deck is empty after this, the deck itself is deleted


## ADD_CARDS \<deck_index> \<number_of_cards>
**(adds cards to a given deck)**

1. Input:
	- deck_index
	- number of cards to be added
	- the cards as seen with the ADD_DECK command
3. Output:
	- if everything worked just fine, "The cards were successfully added to deck \<deck_index>.\n"
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n", "The provided card is not a valid one.\n")


## DECK_NUMBER
**(prints the number of decks)**

1. Output:
	- "The number of decks is \<number of decks>.\n"

## DECK_LEN \<deck_index>
**(prints the number of cards in a given deck)**

1. Input:
	- deck_index
3. Output:
	- if everything worked, "The length of deck \<deck_index> is \<number of cards>.\n".
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n")


## SHUFFLE_DECK \<deck_index>
**(shuffles a deck after a specific rule)**

> Rule: the first half of the deck becomes the second one and vice versa.

```
Example:
Deck: 1, 2, 3, 4, 5
Result: 3, 4, 5, 1, 2
```

1. Input:
	- deck_index
3. Output:
	- if everything worked, "The deck \<deck_index> was successfully shuffled.\n".
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n")

## MERGE_DECKS \<deck1_index> \<deck2_index>
**(merges 2 decks)**

> Rule: the cards are taken one by one from each deck and put in another deck.

```
Example:
Deck 0: 1, 2, 3, 4
Deck 1: 4, 5, 6, 7, 11, 12, 13
Result: 1, 4, 2, 5, 3, 6, 4, 7, 11, 12, 13
```

1. Input:
	- deck indexes
3. Output:
	- if everything worked, "The deck \<deck1_index> and the deck \<deck2_index> were successfully merged.\n".
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n")

## SPLIT_DECK \<deck_index> \<split_index>
**(splits a deck after a specific rule)**

> Rule: the deck is split in 2 decks, one with the cards before split_index and one with the rest.

```
Example:
Deck 0: 1, 2, 3, 4
Deck 1: 7, 8, 9
Deck 2: 12, 13, 14
SPLIT_DECK 0 2
Results: 
	Deck 1a: 1, 2
	Deck 1b: 3, 4
	Deck 2: 7, 8, 9
	Deck 3: 12, 13, 14
```

1. Input:
	- deck index
	- split index
3. Output:
	- if everything worked, "The deck \<deck_index> was successfully split by index \<split_index>.\n".
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n", "The provided index is out of bounds for deck \<deck_index>.\n)

## REVERSE_DECK \<deck_index>
**(reverses the order of the cards in the given deck)**

1. Input:
	- deck_index
3. Output:
	- if everything worked, "The deck \<index_pachet> was successfully reversed.\n".
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n")

## SHOW_DECK \<deck_index>
**(prints the cards in a deck)**

1. Input:
	- deck_index
3. Output:
	- if everything worked, all the cards in the deck will be printed.
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n")

## SHOW_ALL
**(prints the cards in all decks)**

1. Output:
	- if everything worked, all the cards in all decks will be printed.

## SORT_DECK \<deck_index>
**(prints the cards in a deck)**

> Rule: the cards will be sorted in ascending order and if 2 cards have the same number, the criteria will be: first HEART, then SPADE, DIAMOND, CLUB.

1. Input:
	- deck_index
3. Output:
	- if everything worked, "The deck \<index_pachet> was successfully sorted.\n".
	- else it will show a specific message so that the user
knows what didn't work("The provided index is out of bounds for the deck list.\n")

## EXIT
**(exiting the program)**

1. Output:
	- if everything worked, nothing and the program
is terminated

## How to run it
1. Download the files as shown in the repo;
2. Open a terminal and change the current directory with the one containing the code;
3. Run the following commands:
	- make
	- ./tema1
	- the set of commands and numbers/files/strings(data)

## Example
```bash
student@pc:~$ make
gcc -Wall -Wextra -std=c99 -g *.c -o tema1 -lm
student@pc:~$ ./tema1
...(data)
```

> Note: you can run the code using valgrind to keep track of memory leaks(they don't exist I can assure you)

For valgrind run:
```bash
student@pc:~$ make
gcc -Wall -Wextra -std=c99 -g *.c -o tema1 -lm
student@pc:~$ valgrind --leak-check=full -s ./tema1
...(data)
```

# How to check it
1. Download the files as shown in the repo;
2. Open a terminal and change the current directory with the one containing the code;
3. Run the following command:

```bash
student@pc:~$ ./check.sh
```

> You will be prompted with a lot of lines verifying a number of inputs for each command. All the inputs can be found in **in/** folder.

---
Thank you!