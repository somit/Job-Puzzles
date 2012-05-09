#include <stdio.h>
#define MAX 10
struct stack
{
       int top;
       int arr[MAX];
};
void initstack(struct stack *s);
void push(struct stack *s,int item);
void display(struct stack *s);
void reverse(struct stack *s);
int pop(struct stack *s);
int main()
{
   struct stack s;
    char check;int item;
   initstack(&s);
    printf("enter elements \n");
    do
    {
    scanf("%d",&item);             
    push(&s,item);
    printf("more elements(Y/N)?\n");
    fflush(stdin);
    scanf("%c",&check);
    }
    while(check=='Y' || check=='y');
    display(&s);
    reverse(&s);
    display(&s);
    return 0;
}
          
void initstack(struct stack *s)
{
     s->top=-1;
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
int pop(struct stack *s)
{ int val;
    if(s->top==-1)
    {
    printf("stack empty\n");    return ;    }       
   
    val=s->arr[s->top];
    s->top--;
    return val;
}
void display(struct stack *s)
{
     while(s->top!=-1)
     {
      printf("%d",s->arr[s->top]);
      s->top--;
      }
}
void reverse(struct stack *s)
{
     int a,b,t,i;
     t=s->top;
     for(i=s->top;i>=1;i--)
     {
             a=pop(s);
             b=pop(s);
             push(s,a);
             push(s,b); 
     }
     s->top=t-1;
     reverse(s);  
}     
