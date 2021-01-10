#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int main (int argc, char ** argv) {
	FILE *fp;
	size_t line_count = 0;
	char buffer[MAX];
	char *ch;	
	char *sub_string = argv[1];
	ssize_t read;

	if (argc <= 1){
		printf("my-grep: searchterm [file ...]\n");
		exit(1);
	}

	if (argc == 2){
		while(fgets(buffer, MAX, stdin) != NULL){
			if(strstr(buffer, argv[1]) != NULL){
				printf("%s", buffer);		
			}

		}
		exit(0);
	}	
	for (int i = 2 ; i != argc ; i++){
		fp = fopen(argv[i], "r");
		if (fp == NULL){
			printf("my-grep: cannot open file\n");
			exit(1);
		}
		else {
			while((read = getline(&ch, &line_count, fp)) != -1 ){
				if(strstr(ch, sub_string) != NULL){
					printf("%s", ch);
				}
			}
		}
	}
	
	return 0;
}


