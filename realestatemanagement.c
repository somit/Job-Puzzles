#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
//#include "Gaurav M Bhandarkar.h"

long bf=1000;
long sf=2000;
long bb=3000;
long sb=4000;
long bp=5000;
long sp=6000;

typedef struct s_info_flat
{
   char cName[20];
   int iBroom;
   int iLoc;
   int iRate;
   int iFurn;
   int iPno;
   int area;
   int dd;
   int mm;
   int yy;
   char comm[50];
   char email[20];
   long pass;
}snode;


typedef struct b_info_flat
{
   int iBroom;
   int iLoc;
   int iMin_rate;
   int iMax_rate;   //actually is area
   int iFurn;
   char name[30];
   char comm[50];
   char email[20];
   long pass;
}bnode;

typedef struct b_info_plot
{
   int area;
   int iLoc;
   int rate;
   int dev;
   char name[30];
   char comm[50];
   char email[20];
   long pass;
}b_plot;





snode inf;
FILE *fp_flat,*fp_bung,*fp_plot,*fp_flat1;

void intro();
void menu();
void menu1();
void sell_menu();
void buy_menu();
int loc_list(int ,int ,int );
void star(int ,int );
void menu2();
void list();
void loc_info(int );
void errsound(int ,int );
void loading();
int yo(int ,int ,int );
void saveflat(bnode *); //same for flat & bung
void saveflats1(snode *);
void saveplot(b_plot *);  //same for buy & sell plots
int displot(b_plot );
void checkflat1();
void checkbung1();
void checkplot1();
void checkflat2();
void checkbung2();
void checkplot2();
int display(bnode );
char locname(int );
int date1(int * ,int * ,int * );
int displaysellflat(snode );
void menu3();
void menu4();
void pyramid(int ,int ,int );
void back();
void drop(int ,int );
void crash();
void pyramid2();
void drop2(int ,int );
void bounce(char s[],int ,int ,int );
void down(int ,int ,int ,char s[]);
void up(int ,char s[]);
void droplogo(int ,int );
void backlogo();
void logo();
void login_menu();
void password(char pass[]);
long pin(int );
int p_dis_bf(bnode );
int p_dis_sf(snode );
int p_dis_bb(bnode );
int p_dis_sb(snode );
int p_dis_bp(b_plot );
int p_dis_sp(b_plot );

int check_email(char email[]);




int main()

{
	clrscr();

	intro();

	while(1)
	{
		menu();
		getch();
	}
	return(0);
}





int p_dis_bf(bnode buy)
{
		int z;
		clrscr();
		printf("\n\n\n Name : ");
		printf("%s",buy.name);

		printf("\n\n Number of Bedrooms : ");
		if(buy.iBroom==0)
			printf(" Any number available");
		else
			printf("%d",buy.iBroom);

		printf(" \n\n Desired Location : ");
		switch(buy.iLoc)
		{
		   case 1:
				printf("Shivajinagar");
				break;
		   case 2:
				printf("Model Colony");
				break;
		   case 3:
				printf("Kothrud");
				break;
		   case 4:
				printf("Camp");
				break;
		   case 5:
				printf("Wanowrie");
				break;
		   case 6:
				printf("Aundh");
				break;
		   case 7:
				printf("Pashan");
				break;
		   case 8:
				printf("Baner");
				break;
		   case 9:
				printf("Bibewadi");
				break;
		   case 10:
				printf("Pimpri-Chanchawad\n");
				break;
		}
		printf(" \n\n Min Rate : ");
		printf("%d",buy.iMin_rate);

		printf(" \n\n Expected Area : ");
		printf("%d",buy.iMax_rate);

		if(buy.iFurn==1)
		   printf("\n\n Furnished ");
		if(buy.iFurn==2)
		   printf("\n\n Unfurnished ");
		if(buy.iFurn==0)
		   printf("\n\n Any ");

		printf("\n\n Email : ");
		printf("%s",buy.email);

		printf("\n\n Comments :-\n  ");
		printf("%s",buy.comm);


		gotoxy(7,22);
		printf("[ ]Modify\n      [ ]Delete");
		z=yo(8,22,23);
		return(z);
}


int p_dis_sf(snode sell)
{
		int z;
		printf("\n\n\n Name : ");
		printf("%s",sell.cName);

		printf("\n\n Number of Bedrooms : ");
		if(sell.iBroom==0)
			printf(" Any number available");
		else
			printf("%d",sell.iBroom);

		printf(" \n\n Desired Location : ");
		switch(sell.iLoc)
		{
		   case 1:
				printf("Shivajinagar");
				break;
		   case 2:
				printf("Model Colony");
				break;
		   case 3:
				printf("Kothrud");
				break;
		   case 4:
				printf("Camp");
				break;
		   case 5:
				printf("Wanowrie");
				break;
		   case 6:
				printf("Aundh");
				break;
		   case 7:
				printf("Pashan");
				break;
		   case 8:
				printf("Baner");
				break;
		   case 9:
				printf("Bibewadi");
				break;
		   case 10:
				printf("Pimpri-Chanchawad\n");
				break;
		}

		printf(" \n\n Contact Number : ");
		printf("%d",sell.iPno);

		printf(" \n\n Approx. Area : ");
		printf("%d",sell.area);

		if(sell.iFurn==1)
		   printf("\n\n Furnished ");
		if(sell.iFurn==2)
		   printf("\n\n Unfurnished ");
		if(sell.iFurn==0)
		   printf("\n\n Any ");
		printf("\n\n Date of construction(dd/mm/yy) : %d/%d/%d",sell.dd,sell.mm,sell.yy);

		printf("\n email : ");
		printf("%s",sell.email);

		printf("\n\n Comments:-\n ");
		printf("%s",sell.comm);

		printf("\n\n\n\n\n");

		gotoxy(7,22);
		printf("[ ]Modify\n      [ ]Delete");
		z=yo(8,22,23);
		return(z);


}

void login_menu()
{
	int z;
	bnode temp13={ 0 };//1 3
	bnode temp13t={ 0 };

	snode temp24={ 0 };
	snode temp24t={ 0 };

	b_plot temp56={ 0 };

	char pass[20],*endptr,s;
	long pin;
	clrscr();

	password(pass);

	if(pass[0]=='1')
	{
	   pin=strtol(pass,&endptr,10);  //<-------

	   checkflat1();
	   fp_flat=fopen("f:\\1\\flat_b.txt","ab+");
	   temp13.pass=0;
	   while(fread(&temp13,sizeof(temp13),1,fp_flat)==1)
	   {
	      if(temp13.pass==pin)
	      {
		 break;
	      }
	   }
	   fclose(fp_flat);
	   if(temp13.pass!=0)
	   z=p_dis_bf(temp13);

	   else
	   {
	   printf("\n\nINVALID PIN !!!");

	   }

	   switch(z)
	{
	   case 2:
		  clrscr();
		  printf(" \n\n\tAre you sure you want to delete your Account(y/n) : ");
		  flushall();
		  scanf("%c",&s);
		  if(s=='y')
		  {
		     fp_flat1=fopen("f:\\1\\temp.txt","wb");
		     fclose(fp_flat1);

		     fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		     fp_flat=fopen("f:\\1\\flat_b.txt","rb");

		     while(fread(&temp13,sizeof(temp13),1,fp_flat)==1)
		     {
			if(temp13.pass!=pin)
			{
			   fwrite(&temp13,sizeof(temp13),1,fp_flat1);
			}
		     }
		     fclose(fp_flat1);
		     fclose(fp_flat);

		     remove("f:\\1\\flat_b.txt");
		     rename("f:\\1\\temp.txt","f:\\1\\flat_b.txt");

		  }
		  break;


	   case 1:

		  clrscr();
		  printf("\n");
		  saveflat(&temp13);
		  //temp13.pass=pin(1);

		  fp_flat1=fopen("f:\\1\\temp.txt","wb");
		  fclose(fp_flat1);

		  fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		  fp_flat=fopen("f:\\1\\flat_b.txt","rb");


		   fwrite(&temp13,sizeof(temp13),1,fp_flat1);


		   while(fread(&temp13t,sizeof(temp13t),1,fp_flat)==1)
		     {
			if(temp13t.pass!=pin)
			{
			   fwrite(&temp13t,sizeof(temp13),1,fp_flat1);
			}
		     }

		   fclose(fp_flat1);
		   fclose(fp_flat);

		   remove("f:\\1\\flat_b.txt");
		   rename("f:\\1\\temp.txt","f:\\1\\flat_b.txt");
	   case 3:
		  break;

	   case 0:
			break;

	}

	}

//////////////////////////////////////////////////////////////


	if(pass[0]=='2')
	{
	   pin=strtol(pass,&endptr,10);  //<-------

	   checkflat2();
	   fp_flat=fopen("f:\\1\\flat_s.txt","ab+");
	   temp24.pass=0;
	   while(fread(&temp24,sizeof(temp24),1,fp_flat)==1)
	   {
	      if(temp24.pass==pin)
	      {
		 break;
	      }
	   }
	   fclose(fp_flat);
	   if(temp24.pass!=0)
	   z=p_dis_sf(temp24);

	   else
	   {
	   printf("\n\nINVALID PIN !!!");

	   }

	   switch(z)
	{
	   case 2:
		  clrscr();
		  printf(" \n\n\tAre you sure you want to delete your Account(y/n) : ");
		  flushall();
		  scanf("%c",&s);
		  if(s=='y')
		  {
		     fp_flat1=fopen("f:\\1\\temp.txt","wb");
		     fclose(fp_flat1);

		     fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		     fp_flat=fopen("f:\\1\\flat_s.txt","rb");

		     while(fread(&temp24,sizeof(temp24),1,fp_flat)==1)
		     {
			if(temp24.pass!=pin)
			{
			   fwrite(&temp24,sizeof(temp24),1,fp_flat1);
			}
		     }
		     fclose(fp_flat1);
		     fclose(fp_flat);

		     remove("f:\\1\\flat_s.txt");
		     rename("f:\\1\\temp.txt","f:\\1\\flat_s.txt");

		  }
		  break;


	   case 1:

		  clrscr();
		  printf("\n");
		  saveflats1(&temp24);
		  //temp13.pass=pin(1);

		  fp_flat1=fopen("f:\\1\\temp.txt","wb");
		  fclose(fp_flat1);

		  fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		  fp_flat=fopen("f:\\1\\flat_s.txt","rb");


		   fwrite(&temp24,sizeof(temp24),1,fp_flat1);


		   while(fread(&temp24t,sizeof(temp24t),1,fp_flat)==1)
		     {
			if(temp24t.pass!=pin)
			{
			   fwrite(&temp24t,sizeof(temp24),1,fp_flat1);
			}
		     }

		   fclose(fp_flat1);
		   fclose(fp_flat);

		   remove("f:\\1\\flat_s.txt");
		   rename("f:\\1\\temp.txt","f:\\1\\flat_s.txt");
	   case 3:
		  break;

	   case 0:
			break;

	}

	}
/////////////////////////////////////////////////////////////////////////

	if(pass[0]=='3')
	{
	   pin=strtol(pass,&endptr,10);  //<-------

	   checkbung1();
	   fp_flat=fopen("f:\\1\\bung_b.txt","ab+");
	   temp13.pass=0;
	   while(fread(&temp13,sizeof(temp13),1,fp_flat)==1)
	   {
	      if(temp13.pass==pin)
	      {
		 break;
	      }
	   }
	   fclose(fp_flat);
	   if(temp13.pass!=0)
	   z=p_dis_bf(temp13);

	   else
	   {
	   printf("\n\nINVALID PIN !!!");

	   }

	   switch(z)
	{
	   case 2:
		  clrscr();
		  printf(" \n\n\tAre you sure you want to delete your Account(y/n) : ");
		  flushall();
		  scanf("%c",&s);
		  if(s=='y')
		  {
		     fp_flat1=fopen("f:\\1\\temp.txt","wb");
		     fclose(fp_flat1);

		     fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		     fp_flat=fopen("f:\\1\\bung_b.txt","rb");

		     while(fread(&temp13,sizeof(temp13),1,fp_flat)==1)
		     {
			if(temp13.pass!=pin)
			{
			   fwrite(&temp13,sizeof(temp13),1,fp_flat1);
			}
		     }
		     fclose(fp_flat1);
		     fclose(fp_flat);

		     remove("f:\\1\\bung_b.txt");
		     rename("f:\\1\\temp.txt","f:\\1\\bung_b.txt");

		  }
		  break;


	   case 1:

		  clrscr();
		  printf("\n");
		  saveflat(&temp13);
		  //temp13.pass=pin(1);

		  fp_flat1=fopen("f:\\1\\temp.txt","wb");
		  fclose(fp_flat1);

		  fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		  fp_flat=fopen("f:\\1\\bung_b.txt","rb");


		   fwrite(&temp13,sizeof(temp13),1,fp_flat1);


		   while(fread(&temp13t,sizeof(temp13t),1,fp_flat)==1)
		     {
			if(temp13t.pass!=pin)
			{
			   fwrite(&temp13t,sizeof(temp13),1,fp_flat1);
			}
		     }

		   fclose(fp_flat1);
		   fclose(fp_flat);

		   remove("f:\\1\\bung_b.txt");
		   rename("f:\\1\\temp.txt","f:\\1\\bung_b.txt");
	   case 3:
		  break;

	   case 0:
			break;

	}

	}

//////////////////////////////////////////////////////////////



	if(pass[0]=='4')
	{
	   pin=strtol(pass,&endptr,10);  //<-------

	   checkbung2();
	   fp_flat=fopen("f:\\1\\bung_s.txt","ab+");
	   temp24.pass=0;
	   while(fread(&temp24,sizeof(temp24),1,fp_flat)==1)
	   {
	      if(temp24.pass==pin)
	      {
		 break;
	      }
	   }
	   fclose(fp_flat);
	   if(temp24.pass!=0)
	   z=p_dis_sf(temp24);

	   else
	   {
	   printf("\n\nINVALID PIN !!!");

	   }

	   switch(z)
	{
	   case 2:
		  clrscr();
		  printf(" \n\n\tAre you sure you want to delete your Account(y/n) : ");
		  flushall();
		  scanf("%c",&s);
		  if(s=='y')
		  {
		     fp_flat1=fopen("f:\\1\\temp.txt","wb");
		     fclose(fp_flat1);

		     fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		     fp_flat=fopen("f:\\1\\bung_s.txt","rb");

		     while(fread(&temp24,sizeof(temp24),1,fp_flat)==1)
		     {
			if(temp24.pass!=pin)
			{
			   fwrite(&temp24,sizeof(temp24),1,fp_flat1);
			}
		     }
		     fclose(fp_flat1);
		     fclose(fp_flat);

		     remove("f:\\1\\bung_s.txt");
		     rename("f:\\1\\temp.txt","f:\\1\\bung_s.txt");

		  }
		  break;


	   case 1:

		  clrscr();
		  printf("\n");
		  saveflats1(&temp24);
		  //temp13.pass=pin(1);

		  fp_flat1=fopen("f:\\1\\temp.txt","wb");
		  fclose(fp_flat1);

		  fp_flat1=fopen("f:\\1\\temp.txt","ab+");
		  fp_flat=fopen("f:\\1\\bung_s.txt","rb");


		   fwrite(&temp24,sizeof(temp24),1,fp_flat1);


		   while(fread(&temp24t,sizeof(temp24t),1,fp_flat)==1)
		     {
			if(temp24t.pass!=pin)
			{
			   fwrite(&temp24t,sizeof(temp24),1,fp_flat1);
			}
		     }

		   fclose(fp_flat1);
		   fclose(fp_flat);

		   remove("f:\\1\\bung_s.txt");
		   rename("f:\\1\\temp.txt","f:\\1\\bung_s.txt");
	   case 3:
		  break;

	   case 0:
			break;

	}

	}
/////////////////////////////////////////////////////////////////////////



}

//////////////////////////////////////

long pin(int f)
{
	if(f==1)
	{
	   return(bf++);

	}
	if(f==2)
	   return(sf++);

	   if(f==3)
	   return(bb++);
	if(f==4)
	return(sb++);
	if(f==5)
	return(bp++);

	if(f==6)
	return(sp++);

}




void password(char pass1[])
{
	int i=0,b=0,z;
	char pass[20]={'#'},ch;
	clrscr();
	printf("\n\n\n\n\n\n\t\t\tEnter Pin Number : ");
	while(ch!='\r')
	{
	   ch=getch();

	   if(ch!='\b'&&ch!='\0')
	   {
	      if(ch!='\r')
	      {
		 printf("*");
	      }
	      pass[i]=ch;
	      pass[i+1]='\0';
	      i++;
	   }
	   else
	   {
	      if(ch!='\0')
	      {
	      if(i!=0)
	      {
		 if(pass[i-1]!='\0')
		 {
		    clrscr();
		    z=0;
		    printf("\n\n\n\n\n\n\t\t\tEnter Pin Number : ");

		    while(z<(i-1))
		    {
		       printf("*");
		       z++;
		    }

		    i--;
		    pass[i]='\0';
		 }
	      }
	   }
	}
	}
	strcpy(pass1,pass);
}


void menu()
{
	int z;

	menu1();
	z=yo(18,10,13);

	switch(z)
	{
	case 1:
		clrscr();
		buy_menu();
		break;
	case 2:
		clrscr();
		sell_menu();
		break;
	case 3:
		clrscr();
		login_menu();
		break;
	case 4:
		clrscr();
		printf("\n\n\t  Thank You for using our services...");
		getch();
		exit(0);
		break;
	}
}

void sell_menu()
{
	snode sell;

	b_plot pb;

	int z,z1,sflag;
	menu2();
	z=yo(18,10,13);

	switch(z)
	{
	case 1:
		clrscr();

		checkflat2();
		fp_flat=fopen("f:\\1\\flat_s.txt","ab+");

      do
	{
		clrscr();
		//printf("Flats:-");

		saveflats1(&sell);
		clrscr();

		printf("\nFollowing information has been entered :-");
		sflag=displaysellflat(sell);
	 }while(sflag==1);


		sell.pass=pin(2);
		printf("\n\n\tYour PIN is : %ld",sell.pass);
		printf("\n\n\n Please remember your pin number....\n\n");




		fwrite(&sell,sizeof(snode),1,fp_flat);
		fclose(fp_flat);
		break;
	case 2:
		clrscr();

		checkbung2();
		fp_bung=fopen("f:\\1\\bung_s.txt","ab+");


		   do
	{
		clrscr();
		printf("Bunglows:-");
		saveflats1(&sell);
		clrscr();

		printf("\nFollowing information has been entered :-");
		sflag=displaysellflat(sell);
	 }while(sflag==1);


		sell.pass=pin(4);
		printf("\n\n\tYour PIN is : %ld",sell.pass);
		printf("\n\n\n Please remember your pin number....\n\n");





	       //	fseek(fp_bung,sizeof(snode),SEEK_END);
		fwrite(&sell,sizeof(snode),1,fp_bung);
		fclose(fp_bung);
		break;
	case 3:
		clrscr();

		checkplot2();
		fp_plot=fopen("f:\\1\\plot_s.txt","ab+");

		//fseek(fp_plot,sizeof(snode_plot),SEEK_END);


		   do
	{
		clrscr();
		printf("Plots:-\n");


		saveplot(&pb);  // can be improved (medium priority)
		clrscr();

		printf("\nFollowing information has been entered :-");
		sflag=displot(pb);

       }while(sflag==1);

		pb.pass=pin(6);
		printf("\n\n\tYour PIN is : %ld",pb.pass);
		printf("\n\n\n Please remember your pin number....\n\n");


		fwrite(&pb,sizeof(pb),1,fp_plot);
		fclose(fp_plot);
		break;
	case 4:
		break;
	}
}

void buy_menu()
{
	bnode buy;
	snode temp;

	b_plot pb;
	int z,cflag;
	cflag=0;

	menu2();
	z=yo(18,10,13);

	switch(z)
	{
	case 1:
		clrscr();

		checkflat1();
		fp_flat=fopen("f:\\1\\flat_b.txt","ab+");

	do
	{
		clrscr();
		printf("Enter your FLAT requirments...\n");
		saveflat(&buy);  // can be improved (medium priority)
		clrscr();

		printf("\nFollowing information has been entered :-");
		cflag=display(buy);
	 }while(cflag==1);

		loading();
		delay(300);
		clrscr();

		buy.pass=pin(1);
		printf("\n\n\tYour PIN is : %ld",buy.pass);
		printf("\n\n\n Please remember your pin number....\n\n");

		fwrite(&buy,sizeof(buy),1,fp_flat);
		fclose(fp_flat);


		fp_flat=fopen("f:\\1\\flat_s.txt","rb");

		while(fread(&temp,sizeof(snode),1,fp_flat)==1)
		{
			if(temp.iBroom==buy.iBroom || buy.iBroom==0)
			 if(temp.iLoc==buy.iLoc || buy.iLoc==0)
			  if(temp.area==buy.iMax_rate || buy.iMax_rate==0)
			   if(temp.iRate==buy.iMin_rate || buy.iMin_rate==0)
			    if(temp.iFurn==buy.iFurn || buy.iFurn==0)
				printf("\n Contact the following person :  %s ( Ph No :  %d )\nEmail: %s",temp.cName,temp.iPno,temp.email);
		}


		break;

	case 2:
		clrscr();

		checkbung1();
		fp_bung=fopen("f:\\1\\bung_b.txt","ab+");


	do
	{
		clrscr();
		printf("Enter your Bunglow requirments...\n");
		saveflat(&buy);  // can be improved (medium priority)
		clrscr();

		printf("\nFollowing information has been entered :-");
		cflag=display(buy);
	 }while(cflag==1);

		loading();
		delay(300);
		clrscr();


		buy.pass=pin(3);
		printf("\n\n\tYour PIN is : %ld",buy.pass);
		printf("\n\n\n Please remember your pin number....\n\n");

		fwrite(&buy,sizeof(buy),1,fp_bung);






		while(fread(&temp,sizeof(snode),1,fp_bung)==1)
		{
			if(temp.iBroom==buy.iBroom || buy.iBroom==0)
			 if(temp.iLoc==buy.iLoc || buy.iLoc==0)
			  if(temp.iRate<=buy.iMax_rate || buy.iMax_rate==0)
			   if(temp.iRate>=buy.iMin_rate || buy.iMin_rate==0)
			    if(temp.iFurn==buy.iFurn || buy.iFurn==0)
				printf("\n Contact the following person :  %s ( Ph No :  %d )",temp.cName,temp.iPno);
		}

		fclose(fp_bung);
		break;

	case 3:
		clrscr();

		checkplot1();
		fp_plot=fopen("f:\\1\\plot_b.txt","ab+");

		do
	{
		clrscr();
		printf("Enter your PLOT requirments...\n");
		saveplot(&pb);  // can be improved (medium priority)
		clrscr();

		printf("\nFollowing information has been entered :-");
		cflag=displot(pb);
	 }while(cflag==1);

		loading();
		delay(300);
		clrscr();


		pb.pass=pin(5);
		printf("\n\n\tYour PIN is : %ld",pb.pass);
		printf("\n\n\n Please remember your pin number....\n\n");

		fwrite(&pb,sizeof(pb),1,fp_plot);

	     /*	while(fread(&ptemp,sizeof(snode_plot),1,fp_plot)==1)
		{
		       if(ptemp.iArea<=pbuy.iMin_area || pbuy.iMin_area==0)
			if(ptemp.iArea>=pbuy.iMax_area || pbuy.iMax_area==0)
			 if(ptemp.iLoc==pbuy.iLoc || pbuy.iLoc==0)
			  if(ptemp.iRate<=pbuy.iMax_rate || pbuy.iMax_rate==0)
			   if(ptemp.iRate>=pbuy.iMin_rate || pbuy.iMin_rate==0)
			    printf("\n Contact the following person :  %s ( Ph No :  %d )",ptemp.cName,ptemp.iPno);
		}*/
		fclose(fp_plot);
		break;


	}
}


void intro()
{
	char s1[]="* @@@@";
	char s4[]="* ####";
	char s2[]="* $$$$";
	char s3[]="* ’%%%%";
	clrscr();
	printf("\n\n\n\n\t\t\t\t\n\n\n\nBy:--\n\n\n");
	textbackground(7);
	textcolor(2);
	crash();
	bounce(s1,4,15,6);
	bounce(s2,4,14,6);
	bounce(s3,4,13,6);
	bounce(s4,4,12,6);
	pyramid(34,6,5);   //55,15,5
	pyramid2();
	textattr(RED + BLINK);
	cprintf("\n\n\n\n\n\n Press Any Key...");
	textattr(RED);
	logo();

	gotoxy(5,20);

	printf("-------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\t     -all rights reserved");
	getch();
}

int loc_list(int x,int y,int w)         //REM DONT USE YO FUNC.
{
	int z,y1;
	char ch='\0';

	y1=y;
	z=1;


	list();
	star(x,y);

	loc_info(z); //<---------
	while(ch!='\r')
	{
	   ch=getch();
	   if(ch<0 || ch>255 || ch=='\0')
	   {
	      ch=getch();
	      if(ch==80&&y!=w)
	      {
		 gotoxy(x,y);
		 printf(" ");
		 y=y+1;
		 star(x,y);
		 z++;
		 loc_info(z);
	      }

	      if(ch==72&&y1!=y)    //will never change
	      {
		 gotoxy(x,y);
		 printf(" ");
		 y=y-1;
		 star(x,y);
		 z--;
		 loc_info(z);
	      }
	   }
	}

return(z);
}

void loc_info(int a)
{
	gotoxy(50,2);
	switch(a)
	{
	case 1:
		printf("It is close to the Railway   ");
		gotoxy(50,3);
		printf(" and Bus Station             ");
		gotoxy(50,4);
		printf(" close to Pune University    ");
		gotoxy(50,5);
		printf(" Good shopping areas         ");
		gotoxy(50,6);
		printf(" Hotels and theatres         ");

		break;

	case 2:
		printf(" Modern locality             ");
		gotoxy(50,3);
		printf(" Schools and Colleges nearby ");
		gotoxy(50,4);
		printf("FC road and JM road nearby   ");
		gotoxy(50,5);
		printf(" Hospitals , Multiplex, Malls");
		gotoxy(50,6);
		printf(" in vicinity                 ");
		break;

	case 3:
		printf(" Fastest developing area     ");
		gotoxy(50,3);
		printf(" Many Colleges present       ");
		gotoxy(50,4);
		printf(" Close to Mumbai-Pune Highway");
		gotoxy(50,5);
		printf(" Industrial area             ");
		gotoxy(50,6);
		printf(" Well known Hospitals        ");
		break;

	case 4:
		printf(" Shopping Malls present      ");
		gotoxy(50,3);
		printf("Many schools and Institutions");
		gotoxy(50,4);
		printf(" ISKON is present            ");
		gotoxy(50,5);
		printf(" Many Food joints            ");
		gotoxy(50,6);
		printf(" Sasoon Hospital             ");
		break;
	case 5:
		printf("AFMC one of the best medical ");
		gotoxy(50,3);
		printf("college in India             ");
		gotoxy(50,4);
		printf(" Many Army quarters          ");
		gotoxy(50,5);
		printf("                             ");
		gotoxy(50,6);
		printf("                             ");
		break;

	case 6:
		printf(" Fast developing Residential ");
		gotoxy(50,3);
		printf("area                         ");
		gotoxy(50,4);
		printf(" Many good Restaurants       ");
		gotoxy(50,5);
		printf(" Good shopping area          ");
		gotoxy(50,6);
		printf("                             ");
		break;
	case 7:
		printf(" Many IT companies           ");
		gotoxy(50,3);
		printf(" A Residential area          ");
		gotoxy(50,4);
		printf(" Educational Institutions    ");
		gotoxy(50,5);
		printf(" NCL famous research centre  ");
		gotoxy(50,6);
		printf("                             ");
		break;
	case 8:
		printf(" Residential area            ");
		gotoxy(50,3);
		printf(" Proximity to Pune-Banglore  ");
		gotoxy(50,4);
		printf(" Highway                     ");
		gotoxy(50,5);
		printf("                             ");
		gotoxy(50,6);
		printf("                             ");
		break;
	case 9:
		printf(" Educational Institutions    ");
		gotoxy(50,3);
		printf(" Airport in vicinity         ");
		gotoxy(50,4);
		printf(" Residential area            ");
		gotoxy(50,5);
		printf("                             ");
		gotoxy(50,6);
		printf("                             ");
		break;
	case 10:
		printf(" Major industrial area       ");
		gotoxy(50,3);
		printf(" Manufacturing units of      ");
		gotoxy(50,4);
		printf("major companies like TATA    ");
		gotoxy(50,5);
		printf(" Residential area            ");
		gotoxy(50,6);
		printf(" Educational institutions    ");
		break;
	}
}
void list()
{
	printf("\n  [ ]Shivajinagar");
	printf("\n  [ ]Model Colony");
	printf("\n  [ ]Kothrud");
	printf("\n  [ ]Camp");
	printf("\n  [ ]Wanowrie");
	printf("\n  [ ]Aundh");
	printf("\n  [ ]Pashan");
	printf("\n  [ ]Baner");
	printf("\n  [ ]Viman Nagar");
	printf("\n  [ ]Pimpri-Chinchawad\n");
}
void menu1()
{
	clrscr();
	printf("\n\t\t\t     Welcome !!!");
	printf("\n\n\n\n\t\t\t  Enter Your Choice");
	printf("\n\n\n\n \t\t[ ]Buy\n\t\t[ ]Sell\n\t\t[ ]LOGIN\n\t\t[ ]Exit");
}
void menu2()
{
	clrscr();
	printf("\n\t\t\t");
	printf("\n\n\n\n\t\t\t  Enter Your Choice");
	printf("\n\n\n\n \t\t[ ]flats\n\t\t[ ]Bunglows\n\t\t[ ]Plots\n\t\t[ ]Back");
}



void menu4()
{
	clrscr();
	printf("\n\t\t\t");
	printf("\n\n\n\n\t\t\t  Enter Your Choice");
	printf("\n\n\n\n \t\t[ ]flats\n\t\t[ ]Bunglows\n\t\t[ ]Back");
}

void star(int x,int y)
{
gotoxy(x,y);
printf("þ");
}
void errsound(int i,int d)
{
	sound(i);
	delay(d);
	nosound();

}
void loading()
{
		int g;
		clrscr();
		printf("\n\nLOADING : \n");
		gotoxy(23,21);
		printf("¯ °°°°°°°°°°°°°°°°°°°°°°°°° ®");


		for(g=24;g<50;g++)
		{
		gotoxy(g,21);
		printf("Û");
		delay(random(100));
		}
		errsound(6000,250);
		gotoxy(3,25);
		printf("Information uploaded !!!");
		delay(250);

}


int yo(int x,int y,int q)
{
	int z,y1;
	char ch='\0';

	y1=y;
	z=1;

	star(x,y);


	while(ch!='\r')
	{
	   ch=getch();
	   if(ch<0 || ch>255 || ch=='\0')
	   {
	      ch=getch();
	      if(ch==80&&y!=q)
	      {
		 gotoxy(x,y);
		 printf(" ");
		 y=y+1;
		 star(x,y);
		 gotoxy(x,y);
		 z++;
	      }

	      if(ch==72&&y!=y1)     //this co-ordinate will never change
	      {
		 gotoxy(x,y);
		 printf(" ");
		 y=y-1;
		 star(x,y);
		 gotoxy(x,y);
		 z--;
	      }
	   }
	}
return(z);
}


void checkflat1()
{
		fp_flat=fopen("f:\\1\\flat_b.txt","rb");
		if(fp_flat==NULL)
		{
			printf("\n\n  Error reading DATA ");
			printf("\n  Sorry for the inconvenience...");
			getch();
			exit(0);
		}
		fclose(fp_flat);
}

void checkflat2()
{
		fp_flat=fopen("f:\\1\\flat_s.txt","rb");
		if(fp_flat==NULL)
		{
			printf("\n\n  Error reading DATA ");
			printf("\n  Sorry for the inconvenience...");
			getch();
			exit(0);
		}
		fclose(fp_flat);
}

void checkbung1()
{
		fp_bung=fopen("f:\\1\\bung_b.txt","rb");
		if(fp_bung==NULL)
		{
			printf("\n\n  Error reading DATA ");
			printf("\n  Sorry for the inconvenience...");
			getch();
			exit(0);
		}
		fclose(fp_bung);
}

void checkbung2()
{
		fp_bung=fopen("f:\\1\\bung_s.txt","rb");
		if(fp_bung==NULL)
		{
			printf("\n\n  Error reading DATA ");
			printf("\n  Sorry for the inconvenience...");
			getch();
			exit(0);
		}
		fclose(fp_bung);
}

void checkplot1()
{
		fp_plot=fopen("f:\\1\\plot_b.txt","rb");
		if(fp_plot==NULL)
		{
			printf("\n\n  Error reading DATA ");
			printf("\n  Sorry for the inconvenience...");
			getch();
			exit(0);
		}
		fclose(fp_plot);
}

void checkplot2()
{
		fp_plot=fopen("f:\\1\\plot_s.txt","rb");
		if(fp_plot==NULL)
		{
			printf("\n\n  Error reading DATA ");
			printf("\n  Sorry for the inconvenience...");
			getch();
			exit(0);
		}
		fclose(fp_plot);
}

void saveflat(bnode *buy)
{
		int z,x,y,flag;
		flag=1;

		printf("\n  Enter your name : ");
		flushall();
		gets(buy->name);


		printf("\n  Enter the no of bedrooms(0 for any) : ");
		scanf("%d",&(buy->iBroom));


		buy->iLoc=loc_list(4,7,16);  //4,7,16
		gotoxy(15,16);

		printf("\n\n  Enter the maximum rate ie budget (0 for any) : ");
		scanf("%d",&(buy->iMin_rate));
		printf("\n  Enter the expected Area(sq feet) (0 for any) : ");
		scanf("%d",&(buy->iMax_rate));
		printf("\n  Furnished\n  [ ]Yes\n  [ ]No\n  [ ]ANY");
		z=yo(4,23,25);
		if(z==3)
		{
		   z=0;
		}
		buy->iFurn=z;
printf("\n\n\n");

do
{
		x=wherex();
		y=wherey();
		gotoxy(x,y);
		printf("                                             ");
		gotoxy(x,y);
		if(flag==0)
		{
		   printf("INVALID EMAIL !!!");
		}
		delay(250);
		gotoxy(x,y);
		printf("                                             ");
		gotoxy(x,y);
		printf("  e-mail :  ");
		flushall();
		gets(buy->email); //can be improved 2 scan for @ or.com

		flag=check_email(buy->email);
}while(flag==0);
printf("\n  Comments :-\n "); //can be improved(LP)
		flushall();
		gets(buy->comm);

}
int display(bnode buy)
{
		int z;
		printf("\n\n\n Name : ");
		printf("%s",buy.name);

		printf("\n\n Number of Bedrooms : ");
		if(buy.iBroom==0)
			printf(" Any number available");
		else
			printf("%d",buy.iBroom);

		printf(" \n\n Desired Location : ");
		switch(buy.iLoc)
		{
		   case 1:
				printf("Shivajinagar");
				break;
		   case 2:
				printf("Model Colony");
				break;
		   case 3:
				printf("Kothrud");
				break;
		   case 4:
				printf("Camp");
				break;
		   case 5:
				printf("Wanowrie");
				break;
		   case 6:
				printf("Aundh");
				break;
		   case 7:
				printf("Pashan");
				break;
		   case 8:
				printf("Baner");
				break;
		   case 9:
				printf("Bibewadi");
				break;
		   case 10:
				printf("Pimpri-Chanchawad\n");
				break;
		}
		printf(" \n\n Min Rate : ");
		printf("%d",buy.iMin_rate);

		printf(" \n\n Expected Area : ");
		printf("%d",buy.iMax_rate);

		if(buy.iFurn==1)
		   printf("\n\n Furnished ");
		if(buy.iFurn==2)
		   printf("\n\n Unfurnished ");
		if(buy.iFurn==0)
		   printf("\n\n Any ");

		printf("\n\n Email : ");
		printf("%s",buy.email);

		printf("\n\n Comments :-\n  ");
		printf("%s",buy.comm);


		gotoxy(7,22);
		printf("[ ]Change\n      [ ]Save");
		z=yo(8,22,23);
		return(z);

}

void saveflats1(snode *sell)
{
		int z1,mflag,flag,eflag,x,y;
		eflag=1;
		//printf("\n");
		printf("\n  Enter your name : ");
		flushall();
		gets(sell->cName);

		sell->iLoc=loc_list(4,4,13);
		gotoxy(15,15);

		printf("\n  Enter your contact number : ");
		scanf("%d",&sell->iPno);
		printf("\n  Enter the no of bedrooms : ");
		scanf("%d",&sell->iBroom);

		printf("\n  Enter the rate at which you want to sell : ");
		scanf("%d",&sell->iRate);
		printf("\n  Furnished\n  [ ]Yes\n  [ ]No");

		z1=yo(4,23,24);
		sell->iFurn=z1;

		printf("\n  Enter approx. area of flat (sq.feet) : ");
		scanf("%d",&sell->area);

		sell->dd=0;
		sell->mm=0;
		sell->yy=0;
   do
   {
		flag=0;
		printf("\n  Enter Date of purchase : ");
		mflag=date1(&(sell->dd),&(sell->mm),&(sell->yy));

		if(mflag==0||sell->dd<=0||sell->mm<=0||sell->yy<=0)
		{
		   printf("\n  INVALID DATE !!!");
		   flag=1;
		}
   }while(flag==1);


printf("\n\n\n");
do
{


		x=wherex();
		y=wherey();
		gotoxy(x,y);
		printf("                                             ");
		gotoxy(x,y);
		if(eflag==0)
		{
		   printf("INVALID EMAIL !!!");
		}
		delay(200);
		gotoxy(x,y);
		printf("                                             ");
		gotoxy(x,y);
		printf("  e-mail :  ");
		flushall();
		gets(sell->email);

		eflag=check_email(sell->email);
}while(eflag==0);


   printf("\n  Comments :-\n "); //can be improved(Low priority)
	flushall();
	gets(sell->comm);

}


int date1(int *dd,int *mm,int *yy)
{
	int f=0,mm1,yy1,i,b,mflag=0,dec=1,ddz,mmz,yyz;
	long int a;
	char date[20],ch,y,*endptr;

	date[0]='0';

	while(ch!='\r')
	{
	   ch=getche();

	   if(f<6)
	   {
	      f++;
	      date[f]=ch;

	      if(f%2==0&&f!=6)
	      {
		 printf("/");
	      }
	      if(f%2==0&&f==6)
	      {
		 printf("\n");
		 break;
	      }
	   }
	}
	date[f+1]='\0';

	a=strtol(date,&endptr,10);   //Conversion of String To integer

	ddz=a/10000;    //extracting day from 'a'


	*dd=ddz;

	mm1=(a-(*dd*10000));
	mmz=mm1/100;    //extracting month from 'a'


	*mm=mmz;

	yy1=a-(*dd*10000);
	yyz=yy1-(*mm*100); //extracting year from 'a'


	*yy=yyz;

while(dec==1)
{
	if(*mm<=12)
	{
	      if(*mm!=2&&*mm%2==0)
	      {
		 if(*dd<=30&&*mm<=6)
		 {
		    mflag=1;
		    break;
		 }
		 if(*dd<=31&&*mm>6)
		 {
		    mflag=1;
		    break;
		 }
		 else
		 {
		    mflag=0;
		    dec=0;
		    break;
		 }
	      }
	      if(*mm==2)
	      {
		 if(*dd<=28&&*yy%4!=0)
		 {
		    mflag=1;
		    break;
		 }
		 if(*dd<=29&&*yy%4==0)
		 {
		    mflag=1;
		    break;
		 }
		 else
		 {
		    mflag=0;
		    dec=0;
		    break;
		 }
	      }
	      else
	      {
		 if(*mm%2!=0)
		 {
		    if(*dd<=31&&*mm<=7)
		    {
		       mflag=1;
		       break;
		    }
		    if(*dd<=30&&*mm>7)
		    {
		       mflag=1;
		       break;
		    }
		    else
		    {
		       mflag=0;
		       dec=0;
		       break;
		    }
		 }
	      }
	}
dec=0;
}
return(mflag);
}


int displaysellflat(snode sell)
{

		int z;
		printf("\n\n\n Name : ");
		printf("%s",sell.cName);

		printf("\n\n Number of Bedrooms : ");
		if(sell.iBroom==0)
			printf(" Any number available");
		else
			printf("%d",sell.iBroom);

		printf(" \n\n Desired Location : ");
		switch(sell.iLoc)
		{
		   case 1:
				printf("Shivajinagar");
				break;
		   case 2:
				printf("Model Colony");
				break;
		   case 3:
				printf("Kothrud");
				break;
		   case 4:
				printf("Camp");
				break;
		   case 5:
				printf("Wanowrie");
				break;
		   case 6:
				printf("Aundh");
				break;
		   case 7:
				printf("Pashan");
				break;
		   case 8:
				printf("Baner");
				break;
		   case 9:
				printf("Bibewadi");
				break;
		   case 10:
				printf("Pimpri-Chanchawad\n");
				break;
		}

		printf(" \n\n Contact Number : ");
		printf("%d",sell.iPno);

		printf(" \n\n Approx. Area : ");
		printf("%d",sell.area);

		if(sell.iFurn==1)
		   printf("\n\n Furnished ");
		if(sell.iFurn==2)
		   printf("\n\n Unfurnished ");
		if(sell.iFurn==0)
		   printf("\n\n Any ");
		printf("\n\n Date of construction(dd/mm/yy) : %d/%d/%d",sell.dd,sell.mm,sell.yy);

		printf("\n email : ");
		printf("%s",sell.email);

		printf("\n\n Comments:-\n ");
		printf("%s",sell.comm);

		gotoxy(5,22);
		printf("[ ]Change\n    [ ]Save");
		z=yo(6,22,23);
		return(z);
}


void saveplot(b_plot *buy)
{
		int z,eflag,x,y;
		eflag=1;

		printf("\n  Enter your name : ");
		flushall();
		gets(buy->name);


		printf("\n  Industrial or Resi. (0 for any) : ");
		scanf("%d",&(buy->dev));

		buy->iLoc=loc_list(4,7,16);
		gotoxy(15,16);

		printf("\n\n  Enter the maximum rate ie budget (0 for any) : ");
		scanf("%d",&(buy->rate));
		printf("\n  Enter the expected Area(sq feet) (0 for any) : ");
		scanf("%d",&(buy->area));


		printf("\n  e-mail :  ");
		scanf("%s",buy->email); //can be improved 2 scan for @ or.com
printf("\n\n\n");
do
{


		x=wherex();
		y=wherey();
		gotoxy(x,y);
		printf("                                             ");
		gotoxy(x,y);
		if(eflag==0)
		{
		   printf("INVALID EMAIL !!!");
		}
		delay(200);
		gotoxy(x,y);
		printf("                                             ");
		printf("  e-mail :  ");
		flushall();
		gets(buy->email); //can be improved 2 scan for @ or.com

		eflag=check_email(buy->email);
}while(eflag==0);


		printf("\n  Comments :-\n "); //can be improved(LP)
		flushall();
		gets(buy->comm);

}

int displot(b_plot a)
{

	int z;
		printf("\n\n\n Name : ");
		printf("%s",a.name);

		printf("\n\n Ind. or resi. : ");
		if(a.dev==0)
			printf(" Any");
		else
			{
			if(a.dev==1)
			printf(" Ind.");

			else
			printf(" Resi.");
			}

		printf(" \n\n Desired Location : ");
		switch(a.iLoc)
		{
		   case 1:
				printf("Shivajinagar");
				break;
		   case 2:
				printf("Model Colony");
				break;
		   case 3:
				printf("Kothrud");
				break;
		   case 4:
				printf("Camp");
				break;
		   case 5:
				printf("Wanowrie");
				break;
		   case 6:
				printf("Aundh");
				break;
		   case 7:
				printf("Pashan");
				break;
		   case 8:
				printf("Baner");
				break;
		   case 9:
				printf("Bibewadi");
				break;
		   case 10:
				printf("Pimpri-Chanchawad\n");
				break;
		}

		printf(" \n\n Area : ");
		printf("%d",a.area);


		printf("\n email : ");
		printf("%s",a.email);

		printf("\n\n Comments:-\n ");
		printf("%s",a.comm);

		gotoxy(5,22);
		printf("[ ]Change\n    [ ]Save");
		z=yo(6,22,23);
		return(z);
}



void back()
{
	int x,y;
	x=wherex();
	y=wherey();
	gotoxy(34,y-1);
}

void drop(int p,int q)
{
	int i;
	for(i=1;i<=q;i++)
	{
	   gotoxy(p,i);
	   printf("Ü ");
	   delay(25);

	   gotoxy(p,i);


	   if(i!=q)
	   {
	      printf(" ");
	   }

	}
}

void pyramid(int x,int y,int a)
{
	int i,j,z,p,q;
	z=0;
gotoxy(x,y);   
	for(j=0;j<a;j++)
	{
	z=0;
	for(i=j;i<a;i++)
	{
	   z++;
	   p=wherex();
	   q=wherey();
	   drop(p,q);
	   printf("Ü ");
	}
	back();

	 for(z;z<=a;z++)
	   {
	      printf(" ");
	   }

	}
}


void crash()
{
	int i,p,j,q;
	char m[]="Magic";
	char b[]="Bricks";

	p=1;
	q=75;       //change
	gotoxy(p,7);
	for(i=0;i<7;i++)
	{
	   gotoxy(p,7);
	   textattr(CYAN);
	   cprintf("%s",m);
	   gotoxy(q,7);
	   textattr(RED);
	   cprintf("%s",b);
	   delay(500);
	   gotoxy(p,7);
	   printf("     ");
	   gotoxy(q,7);
	   printf("      ");
	   p=p+5;
	   q=q-6;
	}
	textattr(GREEN + BLINK);
	cprintf("\b\b\b\b\b\b\b\b\b\b\b\bMagic Bricks");
	textattr(1);
}

void pyramid2()
{
	int a,i,j,z,p,q;

	a=5;
	gotoxy(34,8);
	for(i=0;i<a;i++)
	{
	   z=0;
	   for(j=i;j<a;j++)
	   {
	      p=wherex();
	      q=wherey();
	      drop2(p,q);
	      printf("Ü ");
	      z++;
	   }
	   printf("\n");
	   gotoxy(34,wherey());
	   for(z;z<=a;z++)
	   {
	      printf(" ");
	   }
	}
}
void drop2(int p,int q)
{
	int i;
	for(i=25;i>=q;i--)
	{
	   gotoxy(p,i);
	   printf("Ü");
	   delay(12);
	   gotoxy(p,i);

	   if(i!=q)
	   {
	      printf(" ");
	   }

	}
}


void bounce(char s[],int x,int y,int b)
{
	int p,i,z;
	p=1;
	down(1,y,x,s);

	while(b>0)
	{
	gotoxy(x,y);
	up(b,s);

	p=wherey();
	down(p,y,x,s);
	b=b-2;
	}
}

void down(int f,int y,int x,char s[]) //f means from where 2 fall down
{
int p;
	p=f;

	while(p<=y)
	{
	   gotoxy(x,p);
	   printf("%s",s);
	   delay(75);
	   if(p!=y)
	   {
	       gotoxy(x,p);
	       printf("                      ");
	   }
	    p=p+1;
	}
}

void up(int b,char s[])
{
	int i,z,x;
	z=wherey();
	x=wherex();
	for(i=0;i<b;i++)
	{
	   gotoxy(x,z);
	   printf("                          ");
	   z=z-1;
	   gotoxy(x,z);
	   printf("%s",s);
	   delay(125);
	}
}


void droplogo(int p,int q)
{
		int i;
	for(i=1;i<=q;i++)
	{
	   gotoxy(p,i);
	   printf("Ü");
	   delay(15);
	   gotoxy(p,i);

	   if(i!=q)
	   {
	      printf(" ");
	   }

	}
}

void backlogo()
{
	int x,y;
	x=wherex();
	y=wherey();
	gotoxy(x,y-1);
       //printf("\r");
}


void logo()
{
	int i,j,p,q,t,flag,c;
	char ch;

	t=0;
	flag=0;
	c=9999;
	gotoxy(55,18);

	for(j=0;j<4;j++)
	{
	for(i=0;i<9;i++)
	{
	   flag=1;
	   p=wherex();
	   q=wherey();

	   droplogo(p,q);
	   t++;
	   if(t==5||t==6||t==15||t==16)
	   {
	   textattr(CYAN + BLINK);
	   cprintf("Ü ");
	   textattr(RED);
	   t++;
	   flag=0;
	   }
	   if(flag==1)
	   printf("Ü ");
	}
	backlogo();
	gotoxy(55,wherey());
	}

	gotoxy(53,16);
	printf("M");
	gotoxy(55,15);
	printf("A");
	gotoxy(57,14);
	printf("G");
	gotoxy(59,13);
	printf("I");
	gotoxy(61,12);
	printf("C");
	gotoxy(63,11);
	printf("B");
	gotoxy(65,12);
	printf("R");
	gotoxy(67,13);
	printf("I");
	gotoxy(69,14);
	printf("C");
	gotoxy(71,15);
	printf("K");
	gotoxy(73,16);
	printf("S");

	ch='\0';
	flushall();
	while(!kbhit())
	{
	  delay(500);
	  gotoxy(67,12);
	  printf("ø");

	  delay(500);
	  gotoxy(67,11);
	  printf("ø");

	  delay(500);
	  gotoxy(67,10);
	  printf("ø");

	  delay(500);
	  gotoxy(67,12);
	  printf(" ");
	  gotoxy(67,11);
	  printf(" ");
	  gotoxy(67,10);
	  printf(" ");
	  c--;
	  }
	  gotoxy(67,12);
	  printf("ø");

	  gotoxy(67,11);
	  printf("ø");

	  gotoxy(67,10);
	  printf("ø");
}

int check_email(char email[])
{
	int i,atcount,dotcount,flag;
	atcount=0;
	dotcount=0;
	flag=0;

	if(email[0]=='@'||email[ ( strlen(email) ) - 1 ]=='@')
	{
	   return(0);
	}

	if(email[0]=='.'||email[ ( strlen(email) ) - 1 ]=='.')
	{
	   return(0);
	}



	for(i=1;i<( strlen(email) );i++)
	{
	   if(email[i]=='@')
	   {
	      atcount++;
	      flag=1;
	      if(email[i+1]=='.')
	      {
		 return(0);
	      }
	   }

	   if(email[i]=='.')
	   {
	      dotcount++;
	      if(flag!=1)
	      {
		 return(0);
	      }
	      if(email[i+1]=='.')
	      {
		 return(0);
	      }
	   }

	   if(email[i]==' ')
	   {
	      return(0);
	   }
	}

	if(atcount>1||atcount<=0)
	{
	   return(0);
	}

	if(dotcount>2||dotcount<=0)
	{
	   return(0);
	}

return(1);
}
