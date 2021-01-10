#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX 512


int main(int argc, char **argv)
{
	FILE *fp;
	int char_count = 1;
	int total_count = 0;
	char prev;
	char curr;



	if (argc < 2)
	{
		printf("%s", "my-zip: file1 [file2 ...]\n");
		exit(1);
	}

	for (int i = 1; i != argc; i++)
	{
		fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			exit(1);
		}
		prev = fgetc(fp);
		while (!feof(fp))
		{

			curr = fgetc(fp);

			if (curr == prev)
			{
				char_count++;
			}
			else
			{
				if (argc == 2)
				{
					fwrite(&char_count, 4, 1, stdout);
					printf("%c", prev);
					prev = curr;
					char_count = 1;
				}
				else
				{
					prev = curr;
					total_count = char_count + total_count;
					char_count = 1;
				}
			}
		}
		fclose(fp);
	}

	return 0;
}

