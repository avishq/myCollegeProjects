#include <stdio.h>
#define M 4
#define N 4
#define s() printf("");
#include <string.h>
#include<stdlib.h>
#include "read.h"
#define bool int

struct tNode
{
   	int data;
	float rating;
   	struct tNode* left;
   	struct tNode* right;
};
 
struct sNode
{
	struct tNode *t;
  	struct sNode *next;
};
 

void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);
 
void preOrder(struct tNode *root, int items[])
{
	int c = 0;
  	struct tNode *current = root;
  	struct sNode *s = NULL;  /* Initialize stack s */
  	bool done = 0;
 
  	while (!done)
  	{
    		if(current !=  NULL)
    		{
      			push(&s, current);                                               
      			current = current->right;  
    		}
        
    		else                                                             
    		{
      			if (!isEmpty(s))
      			{
        			current = pop(&s);
        		//	printf("%d\t%f\n", current->data,current->rating);
				items[c++] = current->data;
 
        			current = current->left;
      			}
      			else
        			done = 1; 
    		}
  	} /* end of while */ 
}     
 
void push(struct sNode** top_ref, struct tNode *t)
{
  	/* allocate tNode */
  	struct sNode* new_tNode = (struct sNode*) malloc(sizeof(struct sNode));
 
  	if(new_tNode == NULL)
  	{
     		printf("Stack Overflow \n");
		exit (0);
  	}            
 
  	/* put in the data  */
  	new_tNode->t  = t;
 
  	/* link the old list off the new tNode */
  	new_tNode->next = (*top_ref);   
 
  	/* move the head to point to the new tNode */
  	(*top_ref)    = new_tNode;
}
 
/* The function returns true if stack is empty, otherwise false */
bool isEmpty(struct sNode *top)
{
   	return (top == NULL)? 1 : 0;
}   
 
/* Function to pop an item from stack*/
struct tNode *pop(struct sNode** top_ref)
{
  	struct tNode *res;
  	struct sNode *top;
 
  	/*If sNode is empty then error */
  	if(isEmpty(*top_ref))
  	{
     		printf("Stack Underflow \n");
          	exit(0);
  	}
  	else
 	{
     		top = *top_ref;
     		res = top->t;
     		*top_ref = top->next;
     		free(top);
     		return res;
  	}
}

void place(struct tNode *r,struct tNode *p)
{
	if(r->rating > p->rating) {
		if ( !r->left){
			r->left = p;
			return;
		} else 
			place(r->left,p);
	} else {
		if ( !r->right){
			r->right = p;
			return;
		} else
			place(r->right,p);
	}
}

struct tNode *create(int d, float r)
{
	struct tNode *p;
	p = (struct tNode *)malloc(sizeof(struct tNode));
	p->data = d;
	p->rating = r;
	p->left = NULL;
	p->right = NULL;

	return p;
}

float sq(float num)
{
	float m, n;
	n=0.0001;   // This is taken small so that we can calculate upto decimal places also
		        //scanf("%f",&num);

	for(m=0;m<num;m=m+n)
		if((m*m)>num) {
			m=m-n;// This if() is used to calculate the final value as soon as the square of the number exceeds
			break;//  the number then we deduct the value exceeded and stop the procedure using break; this is our final value which is stored in m;										        }
		}
	return(m);
}


void pln()
{
	printf("\n_________________________________________________________________________________________\n\n");
	return;
}

void print(int m, int n, float arr[][n])
{
	int i, j;
	pln();
	for ( i = 0; i < m; i++) {
		for ( j = 0; j < n; j++) {
			printf("%f ",arr[i][j]);
		}
		printf("\n");
	}
	return;
}

float mul(float u[][2], float v[][N], int m, int n)
{
	int i;
	int j;
	float sum = 0;
	for ( i = 0; i < 2; i++) {
		sum += u[m][i]* v[i][n];
	}
	return sum;
}

float findError(float o[][N], float t[][N])
{
	printf("Finding Error\n");
	int ctr = 0;
	float f = 0;
	int i;
	int j;
	float diff;
	float sum = 0;

	for ( i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			if (o[i][j] != f){
				ctr++; 
				diff = o[i][j] - t[i][j];
				sum += diff*diff;
			}
		}
	}
	sum /= ctr;
	sum = sq(sum);
	return (sum);
}


void derv(float o[][N],float t[][N], float u[][2], float v[][N],int sel,int i, int j)
{
	int ind;
	float f = 0;
	float c1;
	float c2;
	float newValue = 0;

	printf("sel is %d coordinates %d %d\n",sel,i,j);

	//printf("%d %d %d\n",sel,i,j);
	if (sel == 0) {
		float arr[2][N];

		if (j == 0) {
			c1 = 0;
			c2 = 0;
			float second = u[i][1];
			
			for ( ind = 0; ind < N; ind++) {
				arr[0][ind] = v[0][ind];
				arr[1][ind] = second * v[1][ind];
			}
			for ( ind = 0; ind < N; ind++) {
				if ( o[i][ind] != f) {
					c1 += arr[0][ind] * arr[0][ind];
					c2 +=arr[0][ind] * (o[i][ind]-arr[1][ind]);
				}
			}

			printf("%f\t%f\n",c1,c2);
			newValue = c2/c1;
			u[i][j] = newValue;
		} else if(j == 1){
			c1 = 0;
			c2 = 0;
			float second = u[i][0];

			for ( ind = 0; ind < N; ind++) {
				arr[0][ind] = second * v[0][ind] ;
				arr[1][ind] = v[1][ind];
			}
			for ( ind = 0; ind < N; ind++) {
				if ( o[i][ind] != f) {
					c1 += arr[1][ind]*(o[i][ind]-arr[0][ind]);
					c2 += arr[1][ind] * arr[1][ind];
				}
			}

			printf("%f\t%f\n",c1,c2);
			newValue = c1/c2;
			u[i][j] = newValue;
		}
	} else if ( sel == 1) {
		float arr[M][2];

		if ( i == 0) {
			c1 = 0;
			c2 = 0;
			float second = v[1][j]; //fixed value
			
			for ( ind = 0; ind < M; ind++) {
				arr[ind][0] = u[ind][0];
				arr[ind][1] = u[ind][1] * second;
			}
			for ( ind = 0; ind < M; ind++) {
				if ( o[ind][j] != f) {
					c1 += arr[ind][0]*arr[ind][0];
					c2 += arr[ind][0]*(o[ind][j] - arr[ind][1]);
				}
			}

			printf("%f\t%f\n",c1,c2);
			newValue = c2/c1;
			v[i][j] = newValue;
		} else if ( i == 1) {
			//for the first column of V matrix in which element of v[i][j] has to be find to minimize error
			c1 = 0;
			c2 = 0;
			float second = v[0][j]; //fixed value

			for ( ind = 0; ind < M; ind++) {
				arr[ind][0] = second * u[ind][0];
				arr[ind][1] = u[ind][1];
			}
			for ( ind = 0; ind < M; ind++) {
				if ( o[ind][j] != f) {
					c1 += arr[ind][1]*arr[ind][1];
					c2 += arr[ind][1]*(o[ind][j] - arr[ind][0]);
				}
			}

			printf("%f\t%f\n",c1,c2);
			newValue = c2/c1;
			v[i][j] = newValue;
		}
	}
}

void multiply(float t[][N],float u[][2], float v[][N])
{
	int i, j;
	for ( i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			t[i][j] = mul(u,v,i,j);
		}
	}
	return;
}

int noA(int a[][2], int n)
{
	int i;
	int j;
	int ctr = 0;
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < 2; j++) {
			if ( a[i][j] == 0 && ctr==0) {
				ctr++;
			}
		}
	}
	return ctr;
}

int noB(int a[][N],int n)
{
	int i;
	int j;
	int ctr = 0;
	for ( i = 0; i < 2; i++) {
		for ( j = 0; j < n; j++) {
			if ( a[i][j] == 0 && ctr==0) {
				ctr++;
			}
		}
	}
	return ctr;
}

int notA(int a[][2],int n,int arr[])
{
	int i;
	int j;
	int ctr = 0;
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < 2; j++) {
			if ( a[i][j] == 0 && ctr==0) {
				a[i][j] = 1;
				arr[0] = i;
				arr[1] = j;
				ctr++;
			}
		}
	}
	return ctr;
}

int notB(int a[][N],int n,int arr[])
{
	int i;
	int j;
	int ctr = 0;
	for ( i = 0; i < 2; i++) {
		for ( j = 0; j < n; j++) {
			if ( a[i][j] == 0 && ctr==0) {
				a[i][j] = 1;
				arr[0] = i;
				arr[1] = j;
				ctr++;
			}
		}
	}
	return ctr;
}

void findresult(float o[M][N],float t[M][N],float u[M][2],float v[2][N])
{
	int choice = 0;
	int i;
	float error = 0;
	int ctr = 0;
	int val = 0;
	int val_x;
	int val_y;

	FILE *fp;
	fp = fopen("error.dat","w");
	int a[M][2];
	int b[2][N];
	int detVal[2]; // for finding the i, j indices
	memset(detVal,0,sizeof(detVal));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));

	
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	fprintf(fp,"%d\t%f\n",val++,error);
	printf("======================================================================================\n");

	for ( i = 0; i < 100; i++) {
		while (noA(a,M) || noB(b,N)){
			switch(choice) {
				case 0:
					if (notA(a,M,detVal)) {
						s();
						val_x = detVal[0];
						val_y = detVal[1];
						derv(o,t,u,v,choice,val_x,val_y);
						choice = 1;
						print(M,2,u);
						print(2,N,v);
						multiply(t,u,v);
						print(M,N,t);
						error = findError(o,t);
						printf("error is %f\n",error);
						fprintf(fp,"%d\t%f\n",val++,error);
						printf("======================================================================================\n");
					} else {
				//		memset(a,0,sizeof(a));
					}
				break;
				case 1:
					if (notB(b,N,detVal)) {
						s();
						val_x = detVal[0];
						val_y = detVal[1];
						derv(o,t,u,v,choice,val_x,val_y);
						choice = 0;
						print(M,2,u);
						print(2,N,v);
						multiply(t,u,v);
						print(M,N,t);
						error = findError(o,t);
						printf("error is %f\n",error);
						fprintf(fp,"%d\t%f\n",val++,error);
						printf("======================================================================================\n");
					} else {
				//		memset(b,0,sizeof(b));
					}
				break;
			}
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	fclose(fp);
	return;
}

int main()
{
	FILE *fp;
	int i, j;
	int d;
	float r;
	int c = 0;
	int t_i_g = 0;
	float orig[M][N];
	float tran[M][N];
	float u[M][2];
	float v[2][N];
	struct tNode *root = NULL;

	memset(orig,0,sizeof(orig));	// initialising all the elements 0 of orig matrix

	fp = fopen("data/input.txt","r");

	// Getting Input from the file
	while(getc(fp) != EOF) {
		fseek(fp,-1,SEEK_CUR);
		fscanf(fp,"%d%d%d",&i,&j,&d);
		orig[i][j] = d;
	}
	fclose(fp);			// closing the input file

	for (i = 0; i < M; i++)
		for ( j = 0; j < 2; j++)
			u[i][j] = v[j][i] = 1; 


	print(M,2,u);
	print(2,N,v);
	

	print(M,N,orig);
	findresult(orig,tran,u,v);
	printf("\n\nPrinting the Original matrix\n");
	print(M,N,orig);
	printf("\n\nPrinting the Trained matrix\n");
	print(M,N,tran);

	printf("\nEnter User Id for which you want to find Recommendation : ");
	scanf("%d",&i);

	for ( j = 0; j < N;j++) {
		if ( orig[i][j] == 0) {
			//printf("Item %d with rating %f\n",j,tran[i][j]);
			if (!root) {
				root = create(j,tran[i][j]);
			} else {
				struct tNode *p;
				p = create(j,tran[i][j]);
				place(root,p);
			}
			t_i_g++;
		}
	}

	int items[t_i_g];
	for ( j = 0; j < N; j++) {
		if ( orig[i][j] == 0) {
//			printf("Item %d with rating %f\n",j,tran[i][j]);
			items[c++] = j;
		}
	}


/*                 					MEANT FOR VARIFICATION PURPOSE
	printf("printing tig\n");
	for ( j = 0; j < t_i_g; j++) {
		printf("TIG %d\n",items[j]);
	}
*/
//	printf("BST\n");
	preOrder(root,items);

/*                 					MEANT FOR VARIFICATION PURPOSE
	printf("printing tig\n");
	for ( j = 0; j < t_i_g; j++) {
		printf("TIG %d\n",items[j]);
	}
*/
	final_items_names(i,N,items,t_i_g,tran);
	printf("\n\n");
	return 0;
}
