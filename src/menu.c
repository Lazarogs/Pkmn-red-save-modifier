#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../includes/stuff.h"

void change_name();
void max_money();

void menu(){
	int choice;
	printf("(0) change name \n(1) Max Money\n\nChoose modification : ");
	if ( scanf("%d", &choice) == EOF ){
		puts("An error has occured, couldn't read selection");
		fclose(save);
		exit(EXIT_FAILURE);
	}

	else {
		getchar();
		switch(choice){
			case 0:
				change_name();
				break;
			
			case 1:
				max_money();
				break;

			default:
				puts("The option selected doesn't match any options");
				menu();
				break;
		}
	}
}

void change_name(){
	char name[11];
	printf("Enter name you want with ASCII only characters (recommended 7 characters, max 10) : ");
	fgets(name, 11, stdin);
	for(int i = 0; i < (int) strlen(name); i++){
		if (name[i] <= 0x7a && name[i] >= 0x61){	
		name[i] -= 0x20;
		}
		if (name[i] == '\n'){
			name[i] = '\0';
		}	
	}
	const uint8_t end_name = 0x50;
	fseek(save, 0x2598, SEEK_SET);
	for(int i = 0; i < (int) strlen(name); i++){
		name[i] += 0x3F;
		fwrite(&name[i], 1, 1, save);
		name[i] -= 0x3F;
	}
	fwrite(&end_name, 1, 1, save);
	printf("Changed name to %s\nWant to change something else? (Y/N): ", name);
	char choice = getchar();
	getchar();
	if (choice == 'Y' || choice == 'y'){
		menu();
	}
	else {
		puts("Bye :)");
	}
}

void max_money(){
	const uint8_t MAX_MONEY = 255;
	fseek(save, 0X25F3, SEEK_SET);
	fwrite(&MAX_MONEY, 1, 3, save);
	printf("Maxed money, Want to change something else? (Y/N): ");
	char choice = getchar();
	getchar();
	if (choice == 'Y' || choice == 'y'){
		menu();
	}
	else {
		puts("Bye :)");
	}
}
