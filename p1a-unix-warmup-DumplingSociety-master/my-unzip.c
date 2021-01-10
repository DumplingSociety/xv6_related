#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
	FILE *fp;
	int count = 0, ch;

	if(argc < 2){
		printf("%s", "my-unzip: file1 [file2 ...]\n");
		exit(1);
	}
	// loop all files
	for(int i =1; i !=argc; i++){
		fp = fopen(argv[i], "rb");
	
		if (fp == NULL){
			printf("fp == NULL");
			exit(1);
		}
		// loop a file
		while(fread(&count, sizeof(int), 1, fp) !=0 ){
			ch = fgetc(fp);
			for (int i = 0; i < count; i++){
				printf("%c", ch);

			}
		}

	}
	
    return 0;
}
