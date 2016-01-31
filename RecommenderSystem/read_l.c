#include <stdio.h>

int main()
{
	FILE *fp;
	int i;
	int j;
	char ch[100];
	fp = fopen("movies_t_s.txt","r");
	for ( j = 0; j < 3; j++) {
		fscanf(fp,"%d%[^\n]s",&i,ch);
		printf("%d\t%s\n",i,ch);
	}
	return 0;
}
