#include <stdio.h>
#include "functions.h"
#define MAX 20
main()
{
      int i,k;
      int *a,size,lower;
      printf("Number of elements in array ? \n\n");
      fflush(stdin);
      scanf("%d",&size);
      a=(int *)malloc(size*sizeof(int *));
      array_init(a,size);
      array_print(a,size);
      quicksort(a,0,size-1);
      array_print(a,size);
       




scanf("%d",&k);
}     
      

