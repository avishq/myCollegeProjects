void final_items_names(int arr[],int size)
{
	FILE *fp;
	int i;
	int j;
	char ch[100];
	fp = fopen("data/movies_t_s.txt","r");
	for ( j = 0; j < size; j++) {
		while(1) {
			fscanf(fp,"%d%[^\n]s",&i,ch);
			if ( arr[j] == i) {
				printf("%d\t%s\n",i,ch);
				break;
			}
		}
		fseek(fp,0,SEEK_SET);
	}
	return 0;
}
