#include <stdio.h>
#include <string.h>
#define M 943
#define N 1682

int main()
{
	int i, j;
	int a, b, c, d;
	FILE *fp;
	FILE *np;
	fp = fopen("new.txt","w");
	np = fopen("data/u.data","r");
	float arr[M][N];
	memset(arr,0,sizeof(arr));
/*	for(i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			arr[i][j] = 5;
		}
	}
*/
	while(getc(np) != EOF) {
		fseek(np,-1,SEEK_CUR);
		fscanf(np,"%d%d%d%d",&a,&b,&c,&d);
		arr[a-1][b-1] = c;
		printf("%d\t%d\t%d\n",a,b,c);
	}
	for(i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
		//	printf("%f ",arr[i][j]);
			fprintf(fp,"%f ",arr[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	return 0;
}
