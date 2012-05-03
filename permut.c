# include <stdio.h>
 
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   if (i == n)
     printf("%s\n", a);
   else
   {
        for (j = i; j <= n; j++)
       {  printf("%s\n", a);
         printf("i=%d , j=%d " , i ,j);
         printf("\nBefore swap1: %c,%c,passed=%d \n" , *(a+i) ,*(a+j),i+1);
         swap((a+i), (a+j));
          permute(a, i+1, n);
           printf("Before swap2: %c,%c \n," , *(a+i) ,*(a+j));
          swap((a+i), (a+j)); //backtrack
          printf("\n %c , %c end\n" , *(a+i) ,*(a+j));
          
       }
   }
} 
 
/* Driver program to test above functions */
int main()
{
   char a[] = "ABC";
   permute(a, 0, 2);
   getchar();
   return 0;
}
