#include <stdio.h>
main()
{
     unsigned char p;
      int z;
      printf("enter value \n");
      scanf("%c" , &p);
      z=bitcount(p);
      printf("\n%d",z);
      getchar(); 
      }
int bitcount(x) 
unsigned char x;
	{
 int count;
		for (count=0; x != 0; x>>=1)
			if ( x & 01)
			   count++;
	 	return count;
}

