void final_items_names(int usr, int n,int arr[],int size, float t[][n])
{
	FILE *fp;
	int i;
	int j;
	char ch[100];
	fp = fopen("data/movies_t_s.txt","r");
	printf("\n\n");
	printf("-----------------------------""Our Recommendations""----------------------------\n");
	printf("________________________________________________________________________________\n");
	printf("Item Id\t\tMovie Name\t\tExpected Rating\n");
	printf("________________________________________________________________________________\n\n");
	for ( j = 0; j < size; j++) {
		while(1) {
			fscanf(fp,"%d%[^\n]s",&i,ch);
			if ( arr[j]+1 == i) {
				printf("%d\t%s\t%f\n",i,ch,t[usr][i-1]);
				break;
			}
		}
		fseek(fp,0,SEEK_SET);
	}
	return;
}
