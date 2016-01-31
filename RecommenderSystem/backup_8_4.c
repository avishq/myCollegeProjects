#include <stdio.h>
#define M 5
#define N 5
#include <string.h>

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
//	print(M,N,o);
//	print(M,N,t);
	for ( i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
	//		printf("%d %d\n",i,j);
			if (o[i][j] != f){
	//			printf("Inside not 0\n");
				ctr++; 
				diff = o[i][j] - t[i][j];
				sum += diff*diff;
	//			printf("Sum is %f\n",sum);
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
//	float arr[2][N];
	float newValue = 0;
	printf("sel is %d coordinates %d %d\n",sel,i,j);
	if (sel == 0) {
		float arr[2][N];
		if (j == 0) {
			c1 = 0;
			c2 = 0;
			float second = u[i][1];
			for ( ind = 0; ind < N; ind++) {
			//	printf("hi there\n");
				arr[0][ind] = v[0][ind];
			//	printf("%f %f\n",second,v[1][ind]);
			//	arr[1][ind] =printf("%f\t%f\n",u[i][1],v[1][ind]);
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
	//		printf("hi new hi\n");
			c1 = 0;
			c2 = 0;
			float second = u[i][0];
	//		printf("second is %f\n",second);
			for ( ind = 0; ind < N; ind++) {
			//	float second = u[i][0];
			//	printf("val %f\n",v[0][ind]);
				arr[0][ind] = second * v[0][ind] ;
				arr[1][ind] = v[1][ind];
			//	printf("%f\t%f\n",arr[0][ind],arr[1][ind]);
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
	//		printf("hi sec 2\n");
			c1 = 0;
			c2 = 0;
			float second = v[1][j];
			for ( ind = 0; ind < M; ind++) {
			//	float second = v[1][j];
			//	printf("%f\n",second);
				arr[ind][0] = u[ind][0];
//				printf("%f\n",arr[ind][0]);
				arr[ind][1] = u[ind][1] * second;
//				printf("%f\n",arr[ind][1]);
			}
			for ( ind = 0; ind < M; ind++) {
				if ( o[ind][j] != f) {
					c1 += arr[ind][0]*arr[ind][0];
					c2 += arr[ind][0]*(o[ind][j] - arr[ind][1]);
				}
			}
			for ( ind = 0; ind < M; ind++) {
				printf("%f\t",arr[ind][0]);
			}
			printf("\n");
			for ( ind = 0; ind < M; ind++) {
				printf("%f\t",arr[ind][1]);
			}
			printf("\n");
			printf("%f\t%f\n",c1,c2);
			newValue = c2/c1;
			v[i][j] = newValue;
		} else if ( i == 1) {
			//for the first column of V matrix in which element of v[i][j] has to be find to minimize error
			c1 = 0;
			c2 = 0;
			float second = v[0][j]; //fixed value
			for ( ind = 0; ind < M; ind++) {
			//	float second = v[1][j];
			//	printf("%f\n",second);
				arr[ind][0] = second * u[ind][0];
//				printf("%f\n",arr[ind][0]);
				arr[ind][1] = u[ind][1];
//				printf("%f\n",arr[ind][1]);
			}
			for ( ind = 0; ind < M; ind++) {
				if ( o[ind][j] != f) {
					c1 += arr[ind][1]*arr[ind][1];
					c2 += arr[ind][1]*(o[ind][j] - arr[ind][0]);
				}
			}
			for ( ind = 0; ind < M; ind++) {
				printf("%f\t",arr[ind][0]);
			}
			printf("\n");
			for ( ind = 0; ind < M; ind++) {
				printf("%f\t",arr[ind][1]);
			}
			printf("\n");
			printf("%f\t%f\n",c1,c2);
			newValue = c2/c1;
			v[i][j] = newValue;
		}
	}
/*
	for ( ind = 0; ind < N; ind++) {
		printf("%f\t",arr[0][ind]);
	}
	printf("\n");
	for ( i = 0; i < N; i++) {
		printf("%f\t",arr[1][ind]);
	}
	printf("\n");
*/
//	print(M,2,u);
//	print(2,N,v);
}

void multiply(float t[][N],float u[][2], float v[][N])
{
	int i, j;
	for ( i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			t[i][j] = mul(u,v,i,j);
		}
	}
/*
	for ( i = 0; i < 2; i++) {
		for ( j = 0; j < 2; j++) {
			t[i][] += u[
*/
	return;
}
void findresult(float o[M][N],float t[M][N],float u[M][2],float v[2][N])
{
	float error = 0;

	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,0,0,0);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,1,0,0);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,0,2,0);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,0,2,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,1,1,2);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,1,0,2);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,0,1,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,1,0,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	//from here
	derv(o,t,u,v,0,4,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,1,1,4);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,0,0,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,1,0,3);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,0,1,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	
	
	derv(o,t,u,v,1,1,0);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	
	
	derv(o,t,u,v,0,1,0);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	
	
	derv(o,t,u,v,1,1,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	derv(o,t,u,v,0,3,0);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	
	
	derv(o,t,u,v,1,0,4);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	
	derv(o,t,u,v,0,4,0);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	
	derv(o,t,u,v,1,1,3);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	
	derv(o,t,u,v,0,3,1);
	print(M,2,u);
	print(2,N,v);
	multiply(t,u,v);
	print(M,N,t);
	error = findError(o,t);
	printf("error is %f\n",error);
	printf("======================================================================================\n");
	
	return;
}

/*
void pln()
{
	printf("\n============================================================================\n\n");
	return;
}
*/
int main()
{
	FILE *fp;
	int i, j;
	float orig[M][N] = {{5,2,4,4,3},{3,1,2,4,1},{2,0,3,1,4},{2,5,4,3,5},{4,4,5,4,0}};
	float tran[M][N];
	float u[M][2];
	float v[2][N];
//	memset(u,1,sizeof(u));
	for (i = 0; i < M; i++)
		for ( j = 0; j < 2; j++)
			u[i][j] = v[j][i] = 1; 


	print(M,2,u);
//	pln();
	print(2,N,v);
//	pln();
	
	int a, b, c;
	/*fp = fopen("data.txt","r");
	memset(orig,0,sizeof(orig));
	print(M,N,orig);
	while(getc(fp) != EOF) {
		fseek(fp,-1,SEEK_CUR);
		fscanf(fp,"%d%d%d",&a,&b,&c);
		orig[a][b] = c;
	}
//	pln();*/
	print(M,N,orig);
//	fclose(fp);
	findresult(orig,tran,u,v);

	return 0;
}
