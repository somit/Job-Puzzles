void swap(int *a, int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
void array_init(int *arr,int size)
{   int i;
   //  arr=(int *)malloc(size*sizeof(int *)); // cannot intilize here else arr_init paramtere passed will be garbage
     for(i=0;i<size;i++)
     {
     printf("enter element no %d : ",i);
     scanf("%d",(arr+i));
     }
   
}    
void array_print(int *a,int size)
{    int i;
     printf("\n Array is below \n\n");
     for(i=0;i<size;i++)
     printf("%d \t",a[i]);
}      


void quicksort(int *a,int lower ,int upper)
{
     int i;
     if(upper>lower)
     {
     i=search(a,lower,upper);
     quicksort(a,lower,i-1);
     quicksort(a,i+1,upper);
     }
}

int search(int *a,int lower,int upper)
{
     int t,i;
     int p,q;
     i=a[lower];
     p=lower+1;
     q=upper;
     while(q>=p)
     {
     while(i>=a[p])
     p++;
     while(i<a[q])
     q--;
     if(q>p)
     {
            t=a[p];
            a[p]=a[q];
            a[q]=t;
     }
     }
     
       t=a[lower];
        a[lower]=a[q];
        a[q]=t;;
     return q;
     
}
     
