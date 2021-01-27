HEADERS = ./includes
SRC = ./src
CFLAGS = -Wall -W -pedantic -ansi -std=c99 -O2

output: main.c $(HEADERS)/stuff.h $(SRC)/checksum.c $(SRC)/menu.c
	gcc $(CFLAGS) -o Pkmn_save_modifier main.c $(SRC)/checksum.c $(SRC)/menu.c
