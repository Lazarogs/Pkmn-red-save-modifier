#include <stdio.h>
#include <stdint.h>
#include "../includes/stuff.h"

void checksum(){
	fseek(save, 0x2598, SEEK_SET);
	uint8_t file_byte;
	uint8_t checksum = 0xFF;
	for(int i = 0x2598; i < 0x3522; i++){
		fread(&file_byte, 1, 1, save);
		checksum = checksum - file_byte;
	}
	fseek(save, 1, SEEK_CUR);
	printf("Currently at %lx, checksum = %x\n", ftell(save), checksum);
	fwrite(&checksum, 1, 1, save);
}
