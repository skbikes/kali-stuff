#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUF 64

void print_menu(){
	puts(" -------------------------------------------------------------");
	puts("| 1. Print baglæns                                             |");
	puts("| 2. Print > 1                                                 |");
	puts("| 3. Print < 1                                                 |");
	puts("| Q. Afslut                                                    |");
	puts(" -------------------------------------------------------------");
	puts("\nIndtast dit valg: ");

	fflush(stdout);
}

char *print_backward(char *sName){
	int i, p, size;
	char *sBackward = malloc(BUF);
	size = strlen(sName)-1;

	for(i = 0; i <= size; i++){
		sBackward[i] = sName[size-i];
		//puts(&sBackward[i]);
		//puts(&sName[size-i]);
		//puts(&sBackward[0]);	
	}
	return sBackward;
}

char *return_shiftr(char *sName){
	int i;
	char *shifted = malloc(BUF);
	
	for(i = 0; i < (strlen(sName)-1); i++){
		shifted[i] = (sName[i] >> 1);	
	}
	return shifted;
}

char *return_shiftl(char *sName){
	int i;
	char *shifted = malloc(BUF);
	
	for(i = 0; i < (strlen(sName)-1); i++){
		shifted[i] = (sName[i] << 1);	
	}
	return shifted;
}

int main(int argc, char *argv[]) {
	
	int i;
	
	char name[BUF];
	char *sReturnString;
	char cExit;

	puts ("Indtast navn: ");

	fgets(name, BUF, stdin);
	if(!strchr(name, '\n')){
		name[BUF-1] = 0x00;
		while(fgetc(stdin) != '\n');
	}

	printf("\n\nHej %s\n", name);
	
	do {
		print_menu();


		cExit = (char)tolower(fgetc(stdin));
		while(fgetc(stdin) != '\n');


		printf("\n\n\nDit valg %c\n", cExit);

		switch(cExit){
			case 0x31:
				sReturnString = print_backward(name);				
				puts("Dit navn baglæns er:");
				puts(sReturnString);
				free(sReturnString);
				break;
			case 0x32:
				sReturnString = return_shiftr(name);
				printf("HEX: ");
				for(i = 0; i < strlen(sReturnString);i++) { printf("\\x%x", sReturnString[i]); }
				printf("\nChar(maybe): ");
				for(i = 0; i < strlen(sReturnString);i++) { printf("%c", sReturnString[i]); }
				printf("\n");
				break;
			case 0x33:
				sReturnString = return_shiftl(name);
				printf("HEX: ");
				for(i = 0; i < strlen(sReturnString);i++) { printf("\\x%x", sReturnString[i]); }
				printf("\nChar(maybe): ");
				for(i = 0; i < strlen(sReturnString);i++) { printf("%c", sReturnString[i]); }
				printf("\n");
				break;
			case 0x66:
				main(argc, argv);
				break;
			case 0x71:
				break;
			default:
				puts("Kan du ikke læse?\n");
					
		}				
	}while(cExit != 'q');	
	puts("Tak fordi du brugte denne service!");	
}

















