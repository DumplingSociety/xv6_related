/* Writen by: Xiangwei Li*/
/* Date: 09/04/2020      */
/* Project 01            */

#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int main (int argc, char ** argv) {
	char buffer[MAX];
	FILE *fp;

	for (int i = 1; i< argc; i++){

		/* open fp to read */
		fp = fopen (argv[i], "r");
		if (fp == NULL){
			printf("my-cat: cannot open file\n");
			exit(1);
		};

		/* get content from fp to buffer */
		while(fgets(buffer, sizeof(buffer), fp)){
			printf("%s", buffer);
		}
	}
	return 0;
}
