#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 512


int main (int argc, char ** argv) {
	FILE *fp;
	int char_count =1, last_c=0;
	char buffer[MAX];
	int total_count = 0;
	int curr;
	if(argc < 2){
		printf("%s", "my-zip: file1 [file2 ...]\n");
		exit(1);
	}
	for(int i =1; i != argc; i++){
		fp = fopen(argv[i], "r");
		if(fp == NULL){ 
			exit(1);
		}

		// loop through all files 
		while(fgets(buffer, MAX, fp) != NULL){
			int slen = strlen(buffer);
			curr = buffer[0];

			// loop a file
			for ( int i = 0; i < slen; i++){
				if(buffer[i] == buffer[i+1]){
				char_count++;
				} 
				
				// when the current char neither new line character nor EOF (aa[ab]b)
				else if ((buffer[i] != '\n') && (buffer[i] != '\0' )){
						last_c = buffer[i];

						// run if input is a single file
						if (argc == 2 ) {
							fwrite(&char_count, 4, 1, stdout);
							fwrite(&last_c, 1, 1, stdout);
							char_count = 1;

							// if the current char is EOL  
							if ((buffer[i] == '\n')){
								last_c = buffer[i];
								fwrite(&char_count, 4, 1, stdout);
								fwrite(&last_c, 1, 1, stdout);
								char_count = 1;
							}
						}

				total_count = char_count + total_count;
				char_count = 1;
				}

				// after it encountered a new line character (Test 4)
				else if ((buffer[i] == '\n')){
					if (argc == 2){
					last_c = buffer[i];
					fwrite(&char_count, 4, 1, stdout);
					fwrite(&last_c, 1, 1, stdout);
					char_count = 1;
					}
				}

				// after it encountered a EOF
				else if (buffer[i] == '\0') {
					last_c = buffer[i];
					if (argc == 2){
					fwrite(&char_count, 4, 1, stdout);
					fwrite(&last_c, 1, 1, stdout);
					char_count = 1;
					}
				total_count = char_count + total_count;
				char_count = 1;
				}
				
				

			}
		// deal with multi files
			if((last_c == curr)&&(i == argc -1)&&(argc >2)){
			fwrite(&total_count, 4, 1, stdout);
			fwrite(&last_c, 1, 1, stdout);
			}
		}
	}
	return 0;
}
