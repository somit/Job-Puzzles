#include <stdio.h>

int xstrlen(char *);
void xstrcpy(char *,char *);
void xstrcat(char *,char *);
int xstrcmp(char *,char *);
void show(char *);

int main()
{
    char s4[20],s1[]="kicit";
    char s2[]="Nagpur";
    char s3[20];
    int len;
    printf("enter string s3: \n");
    scanf("%s",s4);
    
    printf("string s1: %s \n",s1);
    len=xstrlen(s1);
    printf("length of string S1: %d\n",len);
    printf("string s2:%s \n",s2);
    xstrcpy(s3,s1);
    printf("string s3 after copying s1 to it: %s\n",s3);
    xstrcat(s3,s2);
    printf("srting s3 after concatenation: %s\n",s3);
    
if(xstrcmp(s1,s2)==0)
printf("the string s1 and s2 are similar\n");
else
printf("the string s1 and s2 are not similar \n");

printf("to exit code press 0:   ");
int i;
scanf("%d",&i);
if(i == 0)
exit(0); 
return 0;

}

  int xstrlen(char *s)
  {   
      int l=0;
      while(*s)
      {
      l++;
      s++;
      }
      return l;
  }
              
  void xstrcpy(char *t,char *s)
   {
       while(*s)
       {
          *t++=*s++;
        
       }
     *t='\0';
   }
   
   void xstrcat(char *t, char *s)
    {
        while(*t)
          t++;
        while(*s)
          *t++=*s++;
        *t='\0';
    }   
    
    int xstrcmp(char *s,char *t)
     {
         while(*s==*t)
         {
           if(!(*s))
           return 0;
           s++;
           t++;
         }
         return(*s-*t);
     }                             



