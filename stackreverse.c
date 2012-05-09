#include <stdio.h>
#define MAX 100
struct stack
{
       int top;
       int arr[MAX];
};
void initstack(struct stack *);
void push(struct stack *,int);
void display(struct stack *);
int pop(struct stack *);
void reverse(struct stack *,int);
main()
{
    struct stack s;
    int check;int item;
    initstack(&s);
    printf("Enter no of elemnts less than 100");
    fflush(stdin);
    scanf("%d",&check);
    printf("enter elements \n");
    do
    {
    fflush(stdin);
    scanf("%d",&item);            
    push(&s,item);
    check --;
    }
    while(check!=0);
   printf("original stack \n"); 
   display(&s);
   printf("\n reversed stack \n"); 
   reverse(&s);
    display(&s);
   scanf("%d",&item);
}
          
void initstack(struct stack *s)
{    
     s->top=-1;
}
void display(struct stack *s)
{   int t;
     t=s->top;
     while(t!=-1)
     {
      printf("%d",s->arr[t--]);
      }
}
void reverse(struct stack *s)
{   
     int a,b,t,i;
     t=s->top;
     for(i=t;i>=pos;i--)
     {       
             a=pop(s);
             b=pop(s);
             push(s,a);
             push(s,b); 
             s->top--;
     }
     s->top=t;
    if(pos!=s->top) reverse(s,pos+1);  
}     
int pop(struct stack *s)
{ int val;
    if(s->top==-1)
    {
    printf("stack empty\n");    return ;    }       
   
    val=s->arr[s->top];
    s->top--;
    return val;
}
void push(struct stack *s,int item)
{   
     if(s->top==MAX-1)
     {
     printf("STACK FULL \n");
     return;
     }
     else s->top++;
     s->arr[s->top] =item;
}
