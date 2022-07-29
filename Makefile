# Copyright 2022 Napruiu Andrei 312CA

CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g

build:
	$(CC) $(CFLAGS) *.c -o tema1 -lm

clean:
	rm *.o image_editor

run:
	./tema1

pack:
	zip -FSr 312CA_AndreiNapruiu_Tema1.zip README.md Makefile *.c *.h

.PHONY: clean pack
