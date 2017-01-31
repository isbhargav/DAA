
#include<stdio.h>
#include<stdlib.h>
//#define A  i,(i+j)/2,k,(k+l)/2
//#define B  i,(i+j)/2,(k+l)/2+1,l
//#define C  (i+j)/2+1,j,k,(k+l)/2
//#define D  (i+j)/2+1,j,(k+l)/2+1,l
//#define E  m,(m+n)/2,o,(o+p)/2
//#define F    m,(m+n)/2,(o+p)/2+1,p
//#define G  (m+n)/2+1,n,o,(o+p)/2
//#define H (m+n)/2+1,n,(o+p)/2+1,p
//  q,(q+r)/2,s,(s+t)/2
//  q,(q+r)/2,(s+t)/2+1,t
//  (q+r)/2+1,r,s,(s+t)/2
// (q+r)/2+1,r,(s+t)/2+1,t
#define MAX 4
void add(int **a,int **b,int **c,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t);
void sub(int **a,int **b,int **c,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t);
void strassens(int **a,int **b,int **c,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t,int size);

int main()
{
	
	int i,j;
	//int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
	int **a,**b,**c;
	
	a  = (int **)malloc(sizeof(int *) * MAX);
    	a[0] = (int *)malloc(sizeof(int) * MAX * MAX);
	for(i = 0; i < MAX; i++)
		a[i] = (*a + MAX * i);	
	b  = (int **)malloc(sizeof(int *) * MAX);
    	b[0] = (int *)malloc(sizeof(int) * MAX * MAX);
	for(i = 0; i < MAX; i++)
		b[i] = (*b + MAX * i);	
	c  = (int **)malloc(sizeof(int *) * MAX);
    	c[0] = (int *)malloc(sizeof(int) * MAX * MAX);
	for(i = 0; i < MAX; i++)
		c[i] = (*c + MAX * i);	



	for(i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
		{
			scanf("%d",&a[i][j]);
		//	b[i][j]=1;
		}
	for(i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
		{
		//	a[i][j]=1;
			scanf("%d",&b[i][j]);
		}
	for(i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
		{
			c[i][j]=0;
			
		}
    //scanf("%d");
	strassens(a,b,c,0,MAX-1,0,MAX-1,0,MAX-1,0,MAX-1,0,MAX-1,0,MAX-1,MAX);	
	for(i=0;i<MAX;i++,printf("\n"))
		for(int j=0;j<MAX;j++)
			    printf("%d ",c[i][j]);
			
	return 0;
}

void add(int **a,int **b,int **c,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t)
{
	for(;i<=j && m<=n && q<=r;i++,m++,q++)
		for(;k<=l && o<=p && s<=t;k++,o++,s++)
			c[q][s]=a[i][k]+b[m][o];
}
void sub(int **a,int **b,int **c,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t)
{
	for(;i<=j && m<=n && q<=r;i++,m++,q++)
		for(;k<=l && o<=p && s<=t;k++,o++,s++)
			c[q][s]=a[i][k]-b[m][o];
}

void strassens(int **a,int **b,int **c,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t,int size)
{
    if(i<0 || j>=MAX || k<0 || l>=MAX || m<0 || n>=MAX || o<0 || p>=MAX || size==0)
		return ;
/*
    if(size==2)
	{
        c[q][s]=a[i][k] * b[m][o] + a[i][l] * b[n][o];
	c[q][t]=a[i][k] * b[m][p] + a[i][l] * b[n][p];
	c[r][s]=a[j][k] * b[m][o] + a[j][l] * b[n][o];
	c[r][t]=a[j][k] * b[m][p] + a[j][l] * b[n][p];
		//printf("%d %d %d %d %d %d %d %d %d %d %d %d",i,j,k,l,m,n,o,p);
	}
*/
    else
    {
	int half=size/2;
	int x,y,z,w;
        int ***S=(int***)malloc(sizeof(int**)*10);
	for(x=0;x<10;x++)
	{	S[x]=(int**)malloc(sizeof(int*)*half);
		for(y=0;y<half;y++)
			S[x][y]=(int*)malloc(sizeof(int)*half*half);
		for(w = 0; w < half; w++)
			S[x][w] = (*(S[x]) + half * w);          //a=S[x] a[0]=S[x][0]  	
	}
	

sub(b,b,S[0], m,(m+n)/2,(o+p)/2+1,p,(m+n)/2+1,n,(o+p)/2+1,p,0,half-1,0,half-1);
add(a,a,S[1],i,(i+j)/2,k,(k+l)/2,i,(i+j)/2,(k+l)/2+1,l,0,half-1,0,half-1);
add(a,a,S[2],(i+j)/2+1,j,k,(k+l)/2,(i+j)/2+1,j,(k+l)/2+1,l,0,half-1,0,half-1);
sub(b,b,S[3], (m+n)/2+1,n,o,(o+p)/2, m,(m+n)/2,o,(o+p)/2,0,half-1,0,half-1);
add(a,a,S[4],i,(i+j)/2,k,(k+l)/2,(i+j)/2+1,j,(k+l)/2+1,l,0,half-1,0,half-1);
add(b,b,S[5],m,(m+n)/2,o,(o+p)/2,(m+n)/2+1,n,(o+p)/2+1,p,0,half-1,0,half-1);
sub(a,a,S[6],i,(i+j)/2,(k+l)/2+1,l,(i+j)/2+1,j,(k+l)/2+1,l,0,half-1,0,half-1);
add(b,b,S[7],(m+n)/2+1,n,o,(o+p)/2,(m+n)/2+1,n,(o+p)/2+1,p,0,half-1,0,half-1);
sub(a,a,S[8],i,(i+j)/2,k,(k+l)/2,(i+j)/2+1,j,k,(k+l)/2,0,half-1,0,half-1);
add(b,b,S[9],m,(m+n)/2,o,(o+p)/2, m,(m+n)/2,(o+p)/2+1,p,0,half-1,0,half-1);
	
	int ***P=(int***)malloc(sizeof(int**)*7);
	for(x=0;x<7;x++)
	{	P[x]=(int**)malloc(sizeof(int*)*half);
		for(y=0;y<half;y++)
			P[x][y]=(int*)malloc(sizeof(int)*half*half);
		for(w = 0; w < half; w++)
			P[x][w] = (*(P[x]) + half * w);          //a=P[x] a[0]=P[x][0]  	
	}

strassens(a,S[0],P[0],i,(i+j)/2,k,(k+l)/2,0,half-1,0,half-1,0,half-1,0,half-1,half);
strassens(b,S[1],P[1],(m+n)/2+1,n,(o+p)/2+1,p,0,half-1,0,half-1,0,half-1,0,half-1,half);
strassens(b,S[2],P[2],m,(m+n)/2,o,(o+p)/2,0,half-1,0,half-1,0,half-1,0,half-1,half);
strassens(a,S[3],P[3],(i+j)/2+1,j,(k+l)/2+1,l,0,half-1,0,half-1,0,half-1,0,half-1,half);
strassens(S[4],S[5],P[4],0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,half);
strassens(S[6],S[7],P[5],0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,half);
strassens(S[8],S[9],P[6],0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,half);

add(P[3],P[4],P[4],0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,0,half-1);
add(P[4],P[5],P[5],0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,0,half-1);
sub(P[5],P[1],c,0,half-1,0,half-1,0,half-1,0,half-1,q,(q+r)/2,s,(s+t)/2);


add(P[0],P[1],c,0,half-1,0,half-1,0,half-1,0,half-1,q,(q+r)/2,(s+t)/2+1,t);

add(P[2],P[3],c,0,half-1,0,half-1,0,half-1,0,half-1,(q+r)/2+1,r,s,(s+t)/2);

add(P[0],P[4],P[4],0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,0,half-1);
add(P[2],P[6],P[6],0,half-1,0,half-1,0,half-1,0,half-1,0,half-1,0,half-1);
sub(P[4],P[6],c,0,half-1,0,half-1,0,half-1,0,half-1,(q+r)/2+1,r,(s+t)/2+1,t);

    }

    
}
