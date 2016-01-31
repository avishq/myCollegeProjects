#include <stdio.h>

int main()
{
	FILE *fp;
	int i;
	fp = fopen("data.txt","w");
	for ( i = 0; i < 25; i++) {
		fprintf(fp,"%d\t%d\t%d\n",rand()%5,rand()%5,rand()%5);
	}

	fclose(fp);
	return 0;
}

