#include <stdio.h> //file i/o
#include <stdlib.h> //exit()
#include <string.h> //strerror()
#include <stdint.h> //int8_t
#include "includes/stuff.h"

FILE * save;

int main(int argc, char ** argv){
	int errno = 0; //errno initialisation

	if (argc != 2){
		fprintf(stderr, "Use : %s <game_file>.sav\n", argv[0]); //program usage
		exit(EXIT_FAILURE);
	}
	save = fopen(argv[1], "rb+"); //open file

	if (save == NULL){ 
		fprintf(stderr, "Error opening file : %s\n", strerror(errno)); //in case we can't open the file
		fclose(save);						       //printf error and close
		exit(EXIT_FAILURE);
	}
	menu();
	checksum();
	fclose(save);	
	return 0;
}
