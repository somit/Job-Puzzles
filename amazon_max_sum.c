#include<stdio.h>

int max1=0,max2=0,max3=0,maxwa=0 ;
int Find_Max_Sum(int A[4][4],int n, int Current_line, int i, int j,int Sum[], int k );
int max(int x,int y,int z);
int main()
{
int A[4][4]={{3},{8,5},{2,3,1},{0,7,4,2}};
int max_sum ;
int Sum[4];
max_sum = Find_Max_Sum(A, 4, 1, 0, 0 , Sum, 0 ); 
printf("answer  %d \n",max_sum);
}
int max(int x,int y,int z)
{
int maxi=x;
if(maxi<y)
maxi=y;

if(maxi<z)
maxi=z;

printf("\n MAXi= %d,x= %d,y=%d ,z=%d",maxi,x,y,z);
return maxi;
}

int Find_Max_Sum(int A[4][4], int n, int Current_line, int i, int j,int Sum[], int k )
{
	if( Current_line > n || i >= n || j>= n || i<0|| j<0 )
	{
		return 0;
	}
	else if( Current_line == n )
	{
		int index, cumulative_sum =0 ;
		Sum[k++] = A[i][j] ;
		
		for(index =0; index < n ; index ++ )
		{
			cumulative_sum+= Sum[index];
		}
                printf("\n cum %d ",cumulative_sum);
		return cumulative_sum ; // return actual vertical sum 
	}
	else
	{
		
		Sum[k++] = A[i][j] ;
		//printf("\nfirst %d , %d \n",i,j);
		max1 =  Find_Max_Sum(A, n, Current_line+1, i+1, j,Sum, k ); // down element
               //printf("\nsecond %d , %d \n",i,j);
		max2 =  Find_Max_Sum(A, n, Current_line+1, i+1, j+1,Sum, k );// right diagal
              //printf("\nthird %d , %d \n",i,j);
		max3 =  Find_Max_Sum(A, n, Current_line+1, i+1, j-1,Sum, k );// left diagonal
		
		int xwa= max(max1, max2, max3); // return max of max1, max2, max3 
                 if(xwa>maxwa) maxwa=xwa;
           return maxwa;                   
	}          
}


