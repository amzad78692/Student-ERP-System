#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13

struct Student
{
   char name[30],fname[30],mname[30],mob[11],aadhar[13],enroll[14];
   char vill[20],po[20],ps[20],dist[20],state[20],pin[7];
   int roll,cdd,cmm,cyyyy,ddd,dmm,dyyyy;
   int phy,chem,math,hindi,english;
}s;

struct Fee
{
   char enroll[14];
   long cFee, cFine, hFee, hFine, other, regFee;
   long dip_cFee, dip_cFine, dip_hFee, dip_hFine, dip_other;
   long totalFee;
}fee;

struct Id
{
   char user[15], tab, pass[15];
}id;

void getkey();
void select(int);
void login();
void logout();
void regs();
void about();
void loginSelect(int);
void hLogin();
void sLogin();
void stLogin();
void drawbox(int,int,int,int);
void drawwindow(char head[30]);
void okSelect(int);
void mainmenu();
void menuSelect(int);
void add();
void check();
void edit();
void Delete();
void result();
void list();
void address(struct Student t);
void showAddress();
void searchSelect(int);
void byName();
void byRoll();
void byEnroll();
void byMobile();
void byAadhar();
void show(int);
void editSelect(int);
void editName();
void editFName();
void editMName();
void editMobile();
void editAddress();
void editDOB();
void addOk(int);
void editData(struct Student t,FILE *fp1);
void report();
void showResult();
void editResult();
void reportSelect(int);
void inputMarks();
void printList(int);
void sMenu();
void sMenuSelect(int);
void feeDetail();
void sDetail();
void sDashboard();

int ch,choice =1;
struct date d;
FILE *fp;

void main()
{
   int click;
   textbackground(BROWN);
   clrscr();
   getdate(&d);
   _setcursortype(0);
   textcolor(WHITE);
   gotoxy(15,1);
   cprintf("=== Subharti Institute of Technology & Engineering ===");
   gotoxy(70,1);
   printf("%d/%d/%d",d.da_day,d.da_mon,d.da_year);
   gotoxy(5,24);
   textcolor(WHITE);
   cprintf("Use Arrow Key to Control");
   gotoxy(50,24);
   textcolor(WHITE+BLINK);
   cprintf("Created By : MD AMZAD");

   textcolor(WHITE);
   lineno30:
   choice=1;
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(2,1);
   textbackground(GREEN);
   cprintf(" Login ");
   textbackground(CYAN);
   gotoxy(10,1);
   cprintf(" Registraton ");
   gotoxy(24,1);
   cprintf(" About ");
   gotoxy(32,1);
   cprintf(" Exit ");
   lineno40:
   getkey();
   switch(ch)
   {
      case RIGHT:
	 click=1;
	 select(click);
	 goto lineno40;
      case LEFT:
	 click=-1;
	 select(click);
	 goto lineno40;
      default:
	 if(ch==13)
	 {
	    switch(choice)
	    {
	       case 1:
		  login();
		  goto lineno30;
	       case 2:
		  regs();
		  goto lineno30;
	       case 3:
		  about();
		  goto lineno30;
	       case 4:
		  exit(0);
	    }
	 }
	 else
	    goto lineno40;
   }
}

void login()
{
   int click;
   textbackground(BLUE);
   clrscr();
   gotoxy(35,5);
   printf("\xB2\xB2\xB2 Login Section \xB2\xB2\xB2");
   choice =1;
   gotoxy(35,7);
   textbackground(GREEN);
   cprintf("1. HOD Login ");
   gotoxy(35,8);
   textbackground(CYAN);
   cprintf("2. Student Login ");
   gotoxy(35,9);
   cprintf("3. Go Back ");
   lineno90:
   getkey();
   switch(ch)
   {
      case UP:
	 click=-1;
	 loginSelect(click);
	 goto lineno90;
      case DOWN:
	 click=1;
	 loginSelect(click);
	 goto lineno90;
      default:
	 if(ch==13)
	 {
	    switch(choice)
	    {
	       case 1:
		  hLogin();
		  break;
	       case 2:
		  sLogin();
		  break;
	       case 3:
		  return;
	    }
	 }
	 else
	    goto lineno90;
   }
}

void hLogin()
{
   char user[15],pass[15];
   int click,i;
   lineno140:
   window(25,6,45,20);
   textbackground(BROWN);
   clrscr();
   gotoxy(2,2);
   printf("Enter Username");
   textbackground(BLUE);
   gotoxy(2,3);
   cprintf("                  ");
   gotoxy(2,5);
   printf("Enter Password");
   gotoxy(2,6);
   cprintf("                  ");
   gotoxy(3,8);
   textbackground(CYAN);
   cprintf(" Ok ");
   gotoxy(11,8);
   cprintf(" Cancel ");
   gotoxy(3,3);
   _setcursortype(2);
   fflush(stdin);
   gets(user);
   gotoxy(3,6);
   fflush(stdin);
   gets(pass);
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   _setcursortype(0);
   lineno160:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno160;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno160;
      default:
	 if(ch==13)
	 {
	    switch(choice)
	    {
	       case 1:
		  break;
	       case 2:
		  return;
	    }
	 }
	 else
	    goto lineno160;
   }
   textbackground(BROWN);
   gotoxy(2,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(2,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(2,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   if(strcmp(user,"amzad786")==0)
   {
      if(strcmp(pass,"Amzad@123")==0)
      {
	 drawwindow("Notification");
	 gotoxy(5,3);
	 printf("Login Successful");
	 while(!kbhit())
	 {
	    gotoxy(2,7);
	    printf("  < Press any key >  ");delay(500);
	    gotoxy(2,7);
	    printf(" << Press any key >> ");delay(500);
	    gotoxy(2,7);
	    printf("<<< Press any key >>>");delay(500);
	 }
	 getch();
	 mainmenu();

      }
      else
      {
	 drawwindow("Warning");
	 gotoxy(5,3);
	 printf("Invalid Password");
	 while(!kbhit())
	 {
	    gotoxy(2,7);
	    printf("  < Press any key >  ");delay(500);
	    gotoxy(2,7);
	    printf(" << Press any key >> ");delay(500);
	    gotoxy(2,7);
	    printf("<<< Press any key >>>");delay(500);
	 }
	 getch();
	 goto lineno140;
      }
   }
   else
   {
      drawwindow("Warning");
      gotoxy(5,3);
      printf("Invalid Username");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      goto lineno140;
   }
}

void mainmenu()
{
   int click,i;
   lineno270:
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   textbackground(GREEN);
   gotoxy(2,1);
   cprintf(" Admission ");
   choice =1;
   gotoxy(14,1);
   textbackground(CYAN);
   cprintf(" Details ");
   gotoxy(24,1);
   cprintf(" Edit ");
   gotoxy(31,1);
   cprintf(" Delete ");
   gotoxy(41,1);
   cprintf(" Result ");
   gotoxy(50,1);
   cprintf(" List ");
   gotoxy(57,1);
   cprintf(" Logout ");
   lineno280:
   getkey();
   switch(ch)
   {
      case RIGHT:
	 click=1;
	 menuSelect(click);
	 goto lineno280;
      case LEFT:
	 click=-1;
	 menuSelect(click);
	 goto lineno280;
      default:
	 if(ch==13)
	 {
	    switch(choice)
	    {
	       case 1:
		  add();
		  goto lineno270;
	       case 2:
		  check();
		  goto lineno270;
	       case 3:
		  edit();
		  goto lineno270;
	       case 4:
		  Delete();
		  goto lineno270;
	       case 5:
		  report();
		  goto lineno270;
	       case 6:
		  list();
		  goto lineno270;
	       case 7:
		  logout();
		  return;
	    }
	 }
	 else
	    goto lineno280;
   }
}

void logout()
{
   int i;
   gotoxy(30,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(30,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(30,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);

   drawwindow("Notification");
   gotoxy(2,3);
   printf("You have successfully");
   gotoxy(2,4);
   printf("logged out.");
   while(!kbhit())
   {
      gotoxy(2,7);
      printf("  < Press any key >  ");delay(500);
      gotoxy(2,7);
      printf(" << Press any key >> ");delay(500);
      gotoxy(2,7);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
}

void add()
{
   struct Student t;
   int enroll;
   char temp[5];
   fp=fopen("student.txt","ab+");    // Opening file
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,3);
   printf("\xB2\xB2\xB2 Admission Form \xB2\xB2\xB2");
   gotoxy(20,5);
   printf("Name");
   textbackground(BROWN);
   gotoxy(35,5);
   cprintf("                         ");
   gotoxy(20,7);
   printf("Father's Name");
   gotoxy(35,7);
   cprintf("                         ");
   gotoxy(20,9);
   printf("Mother's Name");
   gotoxy(35,9);
   cprintf("                         ");
   gotoxy(20,11);
   printf("Date of Birth");
   gotoxy(36,11);printf("DD"); gotoxy(41,11);printf("MM");  gotoxy(46,11);printf("YYYY");
   gotoxy(35,12);cprintf("    "); gotoxy(40,12);cprintf("    "); gotoxy(45,12);cprintf("      ");
   gotoxy(20,14);
   printf("Mobile No.");
   gotoxy(35,14);
   cprintf("                         ");
   gotoxy(20,16);
   printf("Aadhar No.");
   gotoxy(35,16);
   cprintf("                         ");
   gotoxy(20,18);
   printf("Roll No.");
   gotoxy(35,18);
   cprintf("                         ");

   _setcursortype(2);      // Show cursor

   gotoxy(36,5);
   fflush(stdin);
   gets(t.name);  // Input Name
   strupr(t.name);

   gotoxy(36,7);
   fflush(stdin);
   gets(t.fname);  // Input Father's Name
   strupr(t.fname);

   gotoxy(36,9);
   fflush(stdin);
   gets(t.mname);   // Input Mother's Name
   strupr(t.mname);

   gotoxy(36,12);
   fflush(stdin);
   scanf("%d",&t.ddd);
   gotoxy(41,12);
   fflush(stdin);           // Input Date of Birth
   scanf("%d",&t.dmm);
   gotoxy(46,12);
   fflush(stdin);
   scanf("%d",&t.dyyyy);

   t.cdd=d.da_day;
   t.cmm=d.da_mon;         // Setting current date
   t.cyyyy=d.da_year;

   gotoxy(36,14);
   fflush(stdin);
   gets(t.mob);        // Input Mobile number

   gotoxy(36,16);
   fflush(stdin);
   gets(t.aadhar);     // Input aadhar number

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {                                       // Checking aadhar number
      if(strcmp(s.aadhar,t.aadhar)==0)
      {
	 drawwindow("Warning");
	 gotoxy(2,3);
	 printf("Aadhar number already");
	 gotoxy(2,4);
	 printf("exist.");
	 while(!kbhit())
	 {
	    gotoxy(2,7);
	    printf("  < Press any key >  ");delay(500);
	    gotoxy(2,7);
	    printf(" << Press any key >> ");delay(500);
	    gotoxy(2,7);
	    printf("<<< Press any key >>>");delay(500);
	 }
	 getch();
	 _setcursortype(0);
	 fclose(fp);
	 return;
      }
      fseek(fp,1,SEEK_CUR);
   }

   gotoxy(20,18);
   printf("Roll No.");
   gotoxy(35,18);
   cprintf("                         ");
   gotoxy(36,18);
   fflush(stdin);             // Input roll number
   scanf("%d",&t.roll);

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {                                       // Checking roll number
      if(s.roll==t.roll)
      {
	 drawwindow("Warning");
	 gotoxy(2,3);
	 printf("Roll number already");
	 gotoxy(2,4);
	 printf("exist");
	 while(!kbhit())
	 {
	    gotoxy(2,7);
	    printf("  < Press any key >  ");delay(500);
	    gotoxy(2,7);
	    printf(" << Press any key >> ");delay(500);
	    gotoxy(2,7);
	    printf("<<< Press any key >>>");delay(500);
	 }
	 getch();
	 fclose(fp);
	 return;
      }
      fseek(fp,1,SEEK_CUR);
   }

   lineno470:        // Label for enrollment number
   strcpy(t.enroll,"190100000");
   enroll=rand();
   if(enroll<1000 || enroll>=10000)
      goto lineno470;
   itoa(enroll,temp,10);
   strcat(t.enroll,temp);

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {				    // Checking enrollment number
      if(strcmp(s.enroll,t.enroll)==0)
	 goto lineno470;
      fflush(stdin);
      fseek(fp,1,SEEK_CUR);
   }
   address(t);
   return;
}
void address(struct Student t)
{
   int i;
   gotoxy(30,3);
   printf("\xB2\xB2\xB2 Address Form \xB2\xB2\xB2");
   gotoxy(20,5);
   printf("Village");
   gotoxy(35,5);
   cprintf("                         ");
   gotoxy(20,7);
   textbackground(BLUE);
   cprintf("             ");
   gotoxy(20,11);
   cprintf("             ");
   gotoxy(35,12);
   cprintf("                         ");
   gotoxy(20,14);
   cprintf("             ");
   gotoxy(35,14);
   cprintf("                         ");
   gotoxy(20,16);
   cprintf("             ");
   gotoxy(35,16);
   cprintf("                         ");
   gotoxy(20,18);
   cprintf("             ");
   gotoxy(35,18);
   cprintf("                         ");
   textbackground(BROWN);
   gotoxy(20,7);
   printf("Post");
   gotoxy(35,7);
   cprintf("                         ");
   gotoxy(20,9);
   printf("Police Station");
   gotoxy(35,9);
   cprintf("                         ");
   gotoxy(20,11);
   printf("District");
   gotoxy(35,11);
   cprintf("                         ");
   gotoxy(20,13);
   printf("State");
   gotoxy(35,13);
   cprintf("                         ");
   gotoxy(20,15);
   printf("Pin");
   gotoxy(35,15);
   cprintf("                         ");

   gotoxy(36,5);
   fflush(stdin);
   gets(t.vill);       // Input village
   strupr(t.vill);

   gotoxy(36,7);
   fflush(stdin);      // Input post
   gets(t.po);
   strupr(t.po);

   gotoxy(36,9);
   fflush(stdin);      // Input police station
   gets(t.ps);
   strupr(t.ps);

   gotoxy(36,11);
   fflush(stdin);      // Input District
   gets(t.dist);
   strupr(t.dist);

   gotoxy(36,13);
   fflush(stdin);      // Input state
   gets(t.state);
   strupr(t.state);

   gotoxy(36,15);
   fflush(stdin);      // Input pin
   gets(t.pin);

   t.phy=0;
   t.chem=0;
   t.math=0;       // Setting marks
   t.english=0;
   t.hindi=0;

   _setcursortype(0);
   fwrite(&t,sizeof(t),1,fp);      // Writing on file
   fseek(fp,0,SEEK_END);
   fprintf(fp,"\n");
   fclose(fp);

   //feeEdit();

   textbackground(BLUE);
   gotoxy(20,17);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,18);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,18);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);

   drawwindow("Notification");
   gotoxy(5,3);
   printf("Addmision Successful");
   while(!kbhit())
   {
      gotoxy(2,7);
      printf("  < Press any key >  ");delay(500);
      gotoxy(2,7);
      printf(" << Press any key >> ");delay(500);
      gotoxy(2,7);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
   fclose(fp);
   return;
}

void check()
{
   int click;
   window(2,2,79,23);
   textbackground(BLUE);
   fp=fopen("student.txt","rb+");
   if(fp==NULL)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
   getch();
   fclose(fp);
   return;
   }

   gotoxy(30,5);
   printf("\xB2\xB2\xB2 Please choose an option \xB2\xB2\xB2");
   gotoxy(30,8);
   textbackground(GREEN);
   cprintf(" 1. Search by Name ");
   choice=1;
   textbackground(CYAN);
   gotoxy(30,10);
   cprintf(" 2. Search by Roll No. ");
   gotoxy(30,12);
   cprintf(" 3. Search by Enrollment No. ");
   gotoxy(30,14);
   cprintf(" 4. Search by Mobile No. ");
   gotoxy(30,16);
   cprintf(" 5. Search by Aadhar No. ");

   lineno680:
   getkey();
   switch(ch)
   {
      case UP:
	 click=-1;
	 searchSelect(click);
	 goto lineno680;
      case DOWN:
	 click=1;
	 searchSelect(click);
	 goto lineno680;
      case ENTER:
	 switch(choice)
	 {
	    case 1:
	       byName();
	       return;
	    case 2:
	       byRoll();
	       return;
	    case 3:
	       byEnroll();
	       return;
	    case 4:
	       byMobile();
	       return;
	    case 5:
	       byAadhar();
	       return;
	 }
      default:
	 goto lineno680;
   }
}

void byName()
{
   char name[30];
   int flag=0,i, add;
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   _setcursortype(2);
   gotoxy(30,5);
   printf("\xB2\xB2\xB2 Search Section \xB2\xB2\xB2");
   gotoxy(20,7);
   printf("Enter Student Name ");
   gotoxy(40,7);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(41,7);
   gets(name);
   strupr(name);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(20,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(strcmp(name,s.name)==0)
      {
	 add = 1;
	 show(add);
	 flag=1;
	 break;
      }
      fseek(fp,1,SEEK_CUR);
   }
   fclose(fp);
   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();

      return;
   }

}

void byRoll()
{
   int roll,flag=0,i, add;
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   _setcursortype(2);
   gotoxy(30,5);
   printf("\xB2\xB2\xB2 Search Section \xB2\xB2\xB2");
   gotoxy(20,7);
   printf("Enter Roll No.");
   gotoxy(40,7);
   textbackground(BROWN);
   cprintf("        ");
   gotoxy(41,7);
   fflush(stdin);
   scanf("%d",&roll);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(20,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(roll == s.roll)
      {
	 if(ch == -1)
	 {
	    flag = 1;
	    drawwindow("Information");
	    gotoxy(1,3);
	    printf("Name  : %s",s.name);
	    gotoxy(1,4);
	    printf("Enrolment No.:%s",s.enroll);
	    gotoxy(1,5);
	    printf("Roll No.   :%d",s.roll);

	    while(!kbhit())
	    {
	       gotoxy(3,8);
	       printf("  < Press any key >  ");delay(500);
	       gotoxy(3,8);
	       printf(" << Press any key >> ");delay(500);
	       gotoxy(3,8);
	       printf("<<< Press any key >>>");delay(500);
	    }
	    getch();
	    break;
	 }
	 else
	 {
	    add = 1;
	    show(add);
	    flag=1;
	    break;
	 }
      }
      fflush(stdin);
      fseek(fp,1,SEEK_CUR);
   }

   fclose(fp);
   if(flag==0)
   {
      ch=1;
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      return;
   }
}

void byEnroll()
{
   char enroll[14];
   int flag=0,i, add;
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   _setcursortype(2);
   gotoxy(30,5);
   printf("\xB2\xB2\xB2 Search Section \xB2\xB2\xB2");
   gotoxy(20,7);
   printf("Enter Enrollment No.");
   gotoxy(40,7);
   textbackground(BROWN);
   cprintf("              ");
   gotoxy(41,7);
   fflush(stdin);
   gets(enroll);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(20,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(strcmp(enroll,s.enroll)==0)
      {
	 add = 1;
	 show(add);
	 flag=1;
	 break;
      }
      fseek(fp,1,SEEK_CUR);
   }
   fclose(fp);
   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      return;
   }
}

void byMobile()
{
   char mobile[11];
   int flag=0,i, add;
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   _setcursortype(2);
   gotoxy(30,5);
   printf("\xB2\xB2\xB2 Search Section \xB2\xB2\xB2");
   gotoxy(20,7);
   printf("Enter Mobile No.");
   gotoxy(40,7);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(41,7);
   fflush(stdin);
   gets(mobile);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(20,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(strcmp(mobile,s.mob)==0)
      {
	 add = 1;
	 show(add);
	 flag=1;
	 break;
      }
      fseek(fp,1,SEEK_CUR);
   }
   fclose(fp);
   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      return;
   }
}

void byAadhar()
{
   char aadhar[13];
   int flag=0,i, add;
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   _setcursortype(2);
   gotoxy(30,5);
   printf("\xB2\xB2\xB2 Search Section \xB2\xB2\xB2");
   gotoxy(20,7);
   printf("Enter Aadhar No.");
   gotoxy(40,7);
   textbackground(BROWN);
   cprintf("                 ");
   gotoxy(41,7);
   fflush(stdin);
   gets(aadhar);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(20,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(strcmp(aadhar,s.aadhar)==0)
      {
	 add = 1;
	 show(add);
	 flag=1;
	 break;
      }
      fseek(fp,1,SEEK_CUR);
   }
   fclose(fp);
   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      return;
   }
}

void show(int add)
{
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,2);
   printf("\xB2\xB2\xB2 Student Details \xB2\xB2\xB2");
   gotoxy(20,4);
   printf("Name");
   gotoxy(35,4);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(36,4);
   puts(s.name);
   gotoxy(20,6);
   printf("Father's Name");
   gotoxy(35,6);
   cprintf("                         ");
   gotoxy(36,6);
   puts(s.fname);
   gotoxy(20,8);
   printf("Mother's Name");
   gotoxy(35,8);
   cprintf("                         ");
   gotoxy(36,8);
   puts(s.mname);
   gotoxy(20,10);
   printf("Date of Birth");
   gotoxy(36,10);printf("DD"); gotoxy(41,10);printf("MM");  gotoxy(46,10);printf("YYYY");
   gotoxy(35,11);cprintf("    "); gotoxy(40,11);cprintf("    "); gotoxy(45,11);cprintf("      ");
   gotoxy(36,11);printf("%d",s.ddd);gotoxy(41,11);printf("%d",s.dmm);gotoxy(46,11);printf("%d",s.dyyyy);
   gotoxy(20,13);
   printf("Mobile No.");
   gotoxy(35,13);
   cprintf("            ");
   gotoxy(36,13);
   puts(s.mob);
   gotoxy(50,13);
   puts("Roll No.");
   gotoxy(55,13);
   cprintf("     ");
   gotoxy(56,13);
   printf("%d",s.roll);
   gotoxy(20,15);
   printf("Aadhar No.");
   gotoxy(35,15);
   cprintf("                         ");
   gotoxy(36,15);
   puts(s.aadhar);
   gotoxy(20,17);
   printf("Enrollment No.");
   gotoxy(35,17);
   cprintf("                         ");
   gotoxy(36,17);
   puts(s.enroll);
   gotoxy(20,19);
   printf("Addmission Date");
   gotoxy(36,19);printf("DD"); gotoxy(41,19);printf("MM");  gotoxy(46,19);printf("YYYY");
   gotoxy(35,20);cprintf("    "); gotoxy(40,20);cprintf("    "); gotoxy(45,20);cprintf("      ");
   gotoxy(36,20);printf("%d",s.cdd);gotoxy(41,20);printf("%d",s.cmm);gotoxy(46,20);printf("%d",s.cyyyy);

   while(!kbhit())
   {
      gotoxy(20,21);
      printf("  < Press any key to see address >  ");delay(500);
      gotoxy(20,21);
      printf(" << Press any key to see address >> ");delay(500);
      gotoxy(20,21);
      printf("<<< Press any key to see address >>>");delay(500);
   }
   getch();
   if(add == 1)
      showAddress();
}

void showAddress()
{
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,2);
   printf("\xB2\xB2\xB2 Student Address \xB2\xB2\xB2");
   gotoxy(20,4);
   puts("Village");
   gotoxy(35,4);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(36,4);
   puts(s.vill);
   gotoxy(20,6);
   puts("Post office");
   gotoxy(35,6);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(36,6);
   puts(s.po);
   gotoxy(20,8);
   puts("Police Station");
   gotoxy(35,8);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(36,8);
   puts(s.ps);
   gotoxy(20,10);
   puts("District");
   gotoxy(35,10);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(36,10);
   puts(s.dist);
   gotoxy(20,12);
   puts("State");
   gotoxy(35,12);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(36,12);
   puts(s.state);
   gotoxy(20,14);
   puts("Pin");
   gotoxy(35,14);
   textbackground(BROWN);
   cprintf("        ");
   gotoxy(36,14);
   puts(s.pin);
   while(!kbhit())
   {
      gotoxy(20,16);
      printf("  < Press any key >  ");delay(500);
      gotoxy(20,16);
      printf(" << Press any key >> ");delay(500);
      gotoxy(20,16);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
   return;
}

void edit()
{
   int roll,i,flag=0,click, add;
   fp=fopen("student.txt","ab+");
   if(fp==NULL)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,3);
   printf("\xB2\xB2\xB2 Edit Section \xB2\xB2\xB2");
   gotoxy(20,5);
   puts("Enter Roll No.");
   gotoxy(35,5);
   textbackground(BROWN);
   cprintf("      ");
   gotoxy(36,5);
   _setcursortype(2);
   scanf("%d",&roll);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(20,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(roll==s.roll)
      {
	 add = 1;
	 show(add);
	 flag=1;
	 break;
      }
      fseek(fp,1,SEEK_CUR);
   }
   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(25,3);
   puts("Which detail you want to edit");
   gotoxy(30,5);
   textbackground(GREEN);
   cprintf(" 1.Name ");
   choice=1;
   textbackground(CYAN);
   gotoxy(30,6);
   cprintf(" 2.Father's Name ");
   gotoxy(30,7);
   cprintf(" 3.Mother's Name ");
   gotoxy(30,8);
   cprintf(" 4.Date of Birth ");
   gotoxy(30,9);
   cprintf(" 5.Mobile No. ");
   gotoxy(30,10);
   cprintf(" 6.Address ");
   lineno1250:
   getkey();
   switch(ch)
   {
      case UP:
	 click=-1;
	 editSelect(click);
	 goto lineno1250;
      case DOWN:
	 click=1;
	 editSelect(click);
	 goto lineno1250;
      case ENTER:
	 switch(choice)
	 {
	    case 1:
	       editName();
	       break;
	    case 2:
	       editFName();
	       break;
	    case 3:
	       editMName();
	       break;
	    case 4:
	       editDOB();
	       break;
	    case 5:
	       editMobile();
	       break;
	    case 6:
	       editAddress();
	       break;
	 }
	 break;
      default:
	 goto lineno1250;
   }
   return;
}

void editDOB()
{
   FILE *fp1;
   struct Student t;
   int click,i;
   fp1=fopen("temp.dat","ab+");
   if(fp1==NULL)
   {
       drawwindow("Notification");
       gotoxy(3,3);
       puts("Server problem. Please");
       gotoxy(3,4);
       puts("try again later...");
       while(!kbhit())
       {
	  gotoxy(2,7);
	  printf("  < Press any key >  ");delay(500);
	  gotoxy(2,7);
	  printf(" << Press any key >> ");delay(500);
	  gotoxy(2,7);
	  printf("<<< Press any key >>>");delay(500);
       }
       getch();
       fclose(fp);
       return;
   }
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   drawwindow("Edit");
   gotoxy(3,3);
   puts("Enter Date of Birth");
   textbackground(BROWN);
   gotoxy(3,4);printf("DD"); gotoxy(8,4);printf("MM");  gotoxy(13,4);printf("YYYY");
   gotoxy(2,5);cprintf("    "); gotoxy(7,5);cprintf("    "); gotoxy(12,5);cprintf("      ");
   gotoxy(3,8);
   textbackground(CYAN);
   cprintf(" Ok ");
   gotoxy(11,8);
   cprintf(" Cancel ");
   _setcursortype(2);
   gotoxy(3,5);
   scanf("%d",&s.ddd);
   gotoxy(8,5);
   scanf("%d",&s.dmm);
   gotoxy(13,5);
   scanf("%d",&s.dyyyy);
   _setcursortype(0);
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   choice=1;
   lineno1340:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno1340;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno1340;
      case ENTER:
	 if(choice==1)
	 {
	    editData(t,fp1);
	    return;
	 }
	 if(choice==2)
	 {
	    fclose(fp1);
	    return;
	 }
      default:
	 goto lineno1340;
   }
}

void editAddress()
{
   FILE *fp1;
   struct Student t;
   int click,i;
   fp1=fopen("temp.dat","ab+");
   if(fp1==NULL)
   {
       drawwindow("Notification");
       gotoxy(3,3);
       puts("Server problem. Please");
       gotoxy(3,4);
       puts("try again later...");
       while(!kbhit())
       {
	  gotoxy(2,7);
	  printf("  < Press any key >  ");delay(500);
	  gotoxy(2,7);
	  printf(" << Press any key >> ");delay(500);
	  gotoxy(2,7);
	  printf("<<< Press any key >>>");delay(500);
       }
       getch();
       fclose(fp);
       return;
   }
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,3);
   printf("\xB2\xB2\xB2 Address Form \xB2\xB2\xB2");
   gotoxy(20,5);
   printf("Village");
   gotoxy(35,5);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(20,7);
   printf("Post");
   gotoxy(35,7);
   cprintf("                         ");
   gotoxy(20,9);
   printf("Police Station");
   gotoxy(35,9);
   cprintf("                         ");
   gotoxy(20,11);
   printf("District");
   gotoxy(35,11);
   cprintf("                         ");
   gotoxy(20,13);
   printf("State");
   gotoxy(35,13);
   cprintf("                         ");
   gotoxy(20,15);
   printf("Pin");
   gotoxy(35,15);
   cprintf("                         ");
   gotoxy(25,17);
   textbackground(CYAN);
   cprintf(" OK ");
   gotoxy(35,17);
   cprintf(" Cancel ");
   _setcursortype(2);
   gotoxy(36,5);
   fflush(stdin);
   gets(s.vill);       // Input village
   strupr(s.vill);

   gotoxy(36,7);
   fflush(stdin);      // Input post
   gets(s.po);
   strupr(s.po);

   gotoxy(36,9);
   fflush(stdin);      // Input police station
   gets(s.ps);
   strupr(s.ps);

   gotoxy(36,11);
   fflush(stdin);      // Input District
   gets(s.dist);
   strupr(s.dist);

   gotoxy(36,13);
   fflush(stdin);      // Input state
   gets(s.state);
   strupr(s.state);

   gotoxy(36,15);
   fflush(stdin);      // Input pin
   gets(s.pin);
   _setcursortype(0);

   gotoxy(25,17);
   textbackground(GREEN);
   cprintf(" OK ");
   choice=1;
   lineno1400:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 addOk(click);
	 goto lineno1400;
      case RIGHT:
	 click=1;
	 addOk(click);
	 goto lineno1400;
      case ENTER:
	 if(choice==1)
	 {
	    editData(t,fp1);
	    return;
	 }
	 if(choice==2)
	    return;
      default:
	 goto lineno1400;
   }
}

void addOk(int click)
{
   if(click==1)
   {
      if(choice==2)
	 choice=1;
      else
	 choice++;
   }
   if(click==-1)
   {
      if(choice==1)
	 choice=2;
      else
	 choice--;
   }
   switch(choice)
   {
      case 1:
	 gotoxy(25,17);
	 textbackground(GREEN);
	 cprintf(" OK ");
	 textbackground(CYAN);
	 gotoxy(35,17);
	 cprintf(" Cancel ");
	 break;
      case 2:
	 textbackground(GREEN);
	 gotoxy(35,17);
	 cprintf(" Cancel ");
	 gotoxy(25,17);
	 textbackground(CYAN);
	 cprintf(" OK ");
	 break;
   }
}

void editMobile()
{
   FILE *fp1;
   int click,i;
   struct Student t;
   fp1=fopen("temp.dat","ab+");
   if(fp1==NULL)
   {
       drawwindow("Notification");
       gotoxy(3,3);
       puts("Server problem. Please");
       gotoxy(3,4);
       puts("try again later...");
       while(!kbhit())
       {
	  gotoxy(2,7);
	  printf("  < Press any key >  ");delay(500);
	  gotoxy(2,7);
	  printf(" << Press any key >> ");delay(500);
	  gotoxy(2,7);
	  printf("<<< Press any key >>>");delay(500);
       }
       getch();
       fclose(fp);
       return;
   }
   drawwindow("Edit");
   gotoxy(3,3);
   puts("Enter Mobile No.");
   gotoxy(3,4);
   textbackground(BROWN);
   cprintf("                    ");
   gotoxy(3,8);
   textbackground(CYAN);
   cprintf(" Ok ");
   gotoxy(11,8);
   cprintf(" Cancel ");
   _setcursortype(2);
   gotoxy(4,4);
   gets(s.mob);
   _setcursortype(0);
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   choice=1;
   lineno1340:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno1340;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno1340;
      case ENTER:
	 if(choice==1)
	 {
	    editData(t,fp1);
	    return;
	 }
	 if(choice==2)
	    return;
      default:
	 goto lineno1340;
   }
}

void editMName()
{
   FILE *fp1;
   int click,i;
   struct Student t;
   fp1=fopen("temp.dat","ab+");
   if(fp1==NULL)
   {
       drawwindow("Notification");
       gotoxy(3,3);
       puts("Server problem. Please");
       gotoxy(3,4);
       puts("try again later...");
       while(!kbhit())
       {
	  gotoxy(2,7);
	  printf("  < Press any key >  ");delay(500);
	  gotoxy(2,7);
	  printf(" << Press any key >> ");delay(500);
	  gotoxy(2,7);
	  printf("<<< Press any key >>>");delay(500);
       }
       getch();
       fclose(fp);
       return;
   }
   drawwindow("Edit");
   gotoxy(3,3);
   puts("Enter Mother's Name");
   gotoxy(3,4);
   textbackground(BROWN);
   cprintf("                    ");
   gotoxy(3,8);
   textbackground(CYAN);
   cprintf(" Ok ");
   gotoxy(11,8);
   cprintf(" Cancel ");
   _setcursortype(2);
   gotoxy(4,4);
   fflush(stdin);
   gets(s.mname);
   strupr(s.mname);
   _setcursortype(0);
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   choice=1;
   lineno1340:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno1340;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno1340;
      case ENTER:
	 if(choice==1)
	 {
	    editData(t,fp1);
	    return;
	 }
	 if(choice==2)
	    return;
      default:
	 goto lineno1340;
   }
}

void editFName()
{
   int click,i;
   FILE *fp1;
   struct Student t;
   fp1=fopen("temp.dat","ab+");
   if(fp1==NULL)
   {
       drawwindow("Notification");
       gotoxy(3,3);
       puts("Server problem. Please");
       gotoxy(3,4);
       puts("try again later...");
       while(!kbhit())
       {
	  gotoxy(2,7);
	  printf("  < Press any key >  ");delay(500);
	  gotoxy(2,7);
	  printf(" << Press any key >> ");delay(500);
	  gotoxy(2,7);
	  printf("<<< Press any key >>>");delay(500);
       }
       getch();
       fclose(fp);
       return;
   }
   drawwindow("Edit");
   gotoxy(3,3);
   puts("Enter Father's Name");
   gotoxy(3,4);
   textbackground(BROWN);
   cprintf("                    ");
   gotoxy(3,8);
   textbackground(CYAN);
   cprintf(" Ok ");
   gotoxy(11,8);
   cprintf(" Cancel ");
   _setcursortype(2);
   gotoxy(4,4);
   fflush(stdin);
   gets(s.fname);
   strupr(s.fname);
   _setcursortype(0);
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   choice=1;
   lineno1340:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno1340;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno1340;
      case ENTER:
	 if(choice==1)
	 {
	    editData(t,fp1);
	    return;
	 }
	 if(choice==2)
	    return;
      default:
	 goto lineno1340;
   }
}

void editName()
{
   FILE *fp1;
   int click,i;
   struct Student t;
   fp1=fopen("temp.dat","ab+");
   if(fp1==NULL)
   {
       drawwindow("Notification");
       gotoxy(3,3);
       puts("Server problem. Please");
       gotoxy(3,4);
       puts("try again later...");
       while(!kbhit())
       {
	  gotoxy(2,7);
	  printf("  < Press any key >  ");delay(500);
	  gotoxy(2,7);
	  printf(" << Press any key >> ");delay(500);
	  gotoxy(2,7);
	  printf("<<< Press any key >>>");delay(500);
       }
       getch();
       fclose(fp);
       return;
   }
   drawwindow("Edit");
   gotoxy(3,3);
   puts("Enter Student Name");
   gotoxy(3,4);
   textbackground(BROWN);
   cprintf("                    ");
   gotoxy(3,8);
   textbackground(CYAN);
   cprintf(" Ok ");
   gotoxy(11,8);
   cprintf(" Cancel ");
   _setcursortype(2);
   gotoxy(4,4);
   fflush(stdin);
   gets(s.name);
   strupr(s.name);
   _setcursortype(0);
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   choice=1;
   lineno1340:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno1340;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno1340;
      case ENTER:
	 if(choice==1)
	 {
	    editData(t,fp1);
	    return;
	 }
	 if(choice==2)
	    return;
      default:
	 goto lineno1340;
   }
}

void editData(struct Student t, FILE *fp1)
{
   int i;
   fseek(fp1,0,SEEK_END);
   fwrite(&s,sizeof(s),1,fp1);
   rewind(fp);
   while(fread(&t,sizeof(t),1,fp)>0)
   {
      if(s.roll==t.roll)
      {
	 fseek(fp,1,SEEK_CUR);
	 continue;
      }
      else
      {
	 fseek(fp1,0,SEEK_END);
	 fprintf(fp1,"\n");
	 fwrite(&t,sizeof(t),1,fp1);
      }
   }
   fclose(fp);
   fclose(fp1);
   remove("student.txt");
   rename("temp.dat","student.txt");
   textbackground(BLUE);
   gotoxy(5,5);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(5,6);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(5,6);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   drawwindow("Notification");
   gotoxy(2,3);
   printf("Record modified successfull");
   while(!kbhit())
   {
      gotoxy(2,7);
      printf("  < Press any key >  ");delay(500);
      gotoxy(2,7);
      printf(" << Press any key >> ");delay(500);
      gotoxy(2,7);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
}

void Delete()
{
   int roll,i,flag=0,click, add;
   FILE *fp1;
   struct Student t;
   fp=fopen("student.txt","ab+");
   fp1=fopen("temp.dat","ab+");
   if(fp==NULL || fp1==NULL)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      fclose(fp1);
      return;
   }
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,3);
   printf("\xB2\xB2\xB2 Delete Section \xB2\xB2\xB2");
   gotoxy(20,5);
   puts("Enter Roll No.");
   gotoxy(35,5);
   textbackground(BROWN);
   cprintf("      ");
   gotoxy(36,5);
   _setcursortype(2);
   scanf("%d",&roll);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(20,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(20,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(20,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(roll==s.roll)
      {
	 add = 1;
	 show(add);
	 flag=1;
	 break;
      }
      fseek(fp,1,SEEK_CUR);
   }

   drawwindow("Warning");
   gotoxy(2,3);
   printf("Are you shure want to");
   gotoxy(2,4);
   printf("delete this student ?");
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   gotoxy(11,8);
   textbackground(CYAN);
   cprintf(" Cancel ");
   choice=1;
   lineno1340:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno1340;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno1340;
      case ENTER:
	 if(choice==1)
	    break;
	 if(choice==2)
	 {
	    fclose(fp);
	    fclose(fp1);
	    return;
	 }
      default:
	 goto lineno1340;
   }

   textbackground(BLUE);
   gotoxy(5,5);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(5,6);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(5,6);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);
   drawwindow("Notification");
   gotoxy(2,3);
   printf("Record deleted successfull");
   while(!kbhit())
   {
      gotoxy(2,7);
      printf("  < Press any key >  ");delay(500);
      gotoxy(2,7);
      printf(" << Press any key >> ");delay(500);
      gotoxy(2,7);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();

   if(flag==1)
   {
      rewind(fp);
      while(fread(&t,sizeof(t),1,fp)>0)
      {
	 if(s.roll==t.roll)
	 {
	    fseek(fp,1,SEEK_CUR);
	    continue;
	 }
	 else
	 {
	    fwrite(&t,sizeof(t),1,fp1);
	    fseek(fp1,0,SEEK_END);
	    fprintf(fp1,"\n");
	 }
      }
      fclose(fp);
      fclose(fp1);
      remove("student.txt");
      rename("temp.dat","student.txt");
      return;
   }
   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
}

void report()
{
   int select;
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,5);
   printf("\xB2\xB2\xB2 Result Section \xB2\xB2\xB2");
   textbackground(GREEN);
   choice=1;
   gotoxy(30,7);
   cprintf(" 1.Generate result ");
   gotoxy(30,8);
   textbackground(CYAN);
   cprintf(" 2.View result ");
   gotoxy(30,9);
   cprintf(" 3.Go Back ");
   lineno2080:
   getkey();
   switch(ch)
   {
      case UP:
	 select=-1;
	 reportSelect(select);
	 goto lineno2080;
      case DOWN:
	 reportSelect(select);
	 select=1;
	 goto lineno2080;
      case ENTER:
	 switch(choice)
	 {
	    case 1:
	       editResult();
	       break;
	    case 2:
	       result();
	       break;
	    case 3:
	       return;
	 }
	 break;
      default:
	 goto lineno2080;
   }
}

void editResult()
{
   int roll,flag=0,i;
   FILE *fp=fopen("student.txt","ab+");
   if(fp==NULL)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
   drawwindow("Marksheet");
   gotoxy(3,3);
   puts("Enter Roll No.");
   gotoxy(3,4);
   textbackground(BLUE);
   cprintf("     ");
   _setcursortype(2);
   gotoxy(4,4);
   scanf("%d",&roll);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(5,6);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(5,7);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(5,7);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(roll==s.roll)
      {
	 flag=1;
	 showResult();
	 break;
      }
   }

   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }

   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(25,3);
   printf("\xB2\xB2\xB2 Marksheet Modification \xB2\xB2\xB2");
   gotoxy(25,4);
   printf("Name     : %s",s.name);
   gotoxy(20,5);
   puts("-:Enter the marks of all subject:-");
   gotoxy(20,7);
   puts("Physics");
   textbackground(BROWN);
   gotoxy(35,7);
   cprintf("     ");
   gotoxy(20,9);
   puts("Chemistry");
   gotoxy(35,9);
   cprintf("     ");
   gotoxy(20,11);
   puts("Mathematics");
   gotoxy(35,11);
   cprintf("     ");
   gotoxy(20,13);
   puts("English");
   gotoxy(35,13);
   cprintf("     ");
   gotoxy(20,15);
   puts("Hindi");
   gotoxy(35,15);
   cprintf("     ");
   gotoxy(25,17);
   textbackground(GREEN);
   choice=1;
   cprintf(" OK ");               //addOk function
   gotoxy(35,17);
   textbackground(CYAN);
   cprintf(" Cancel ");
   inputMarks();
}

void inputMarks()
{
   int i,select;
   struct Student t;
   FILE *fp1=fopen("temp.dat","ab+");
   _setcursortype(2);
   gotoxy(36,7);
   scanf("%d",&s.phy);
   gotoxy(36,9);
   scanf("%d",&s.chem);
   gotoxy(36,11);
   scanf("%d",&s.math);
   gotoxy(36,13);
   scanf("%d",&s.english);
   gotoxy(36,15);
   scanf("%d",&s.hindi);
   _setcursortype(0);

   lineno2250:
   getkey();
   switch(ch)
   {
      case LEFT:
	 select=-1;
	 addOk(select);
	 goto lineno2250;
      case RIGHT:
	 select=1;
	 addOk(select);
	 goto lineno2250;
      case ENTER:
	 if(choice==1)
	    goto lineno2270;
	 else
	 {
	    fclose(fp);
	    fclose(fp1);
	    return;
	 }
      default:
	 goto lineno2250;
   }

   lineno2270:
   rewind(fp);
   fseek(fp1,0,SEEK_END);
   fwrite(&s,sizeof(s),1,fp1);
   rewind(fp);
   while(fread(&t,sizeof(t),1,fp)>0)
   {
      if(s.roll==t.roll)
      {
	 fseek(fp,1,SEEK_CUR);
	 continue;
      }
      else
      {
	 fseek(fp1,0,SEEK_END);
	 fprintf(fp1,"\n");
	 fwrite(&t,sizeof(t),1,fp1);
      }
   }
   fclose(fp);
   fclose(fp1);
   remove("student.txt");
   rename("temp.dat","student.txt");


   textbackground(BLUE);
   gotoxy(30,19);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(30,20);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(30,20);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);


   drawwindow("Notification");
   gotoxy(2,3);
   printf("Marksheet modified");
   gotoxy(2,4);
   printf("successfull...");
   while(!kbhit())
   {
      gotoxy(2,7);
      printf("  < Press any key >  ");delay(500);
      gotoxy(2,7);
      printf(" << Press any key >> ");delay(500);
      gotoxy(2,7);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
}

void reportSelect(int select)
{
   if(select==-1)
   {
      if(choice==1)
	 choice=3;
      else
	 choice--;
   }
   else
   {
      if(choice==3)
	 choice=1;
      else
	 choice++;
   }
   switch(choice)
   {
      case 1:
	 textbackground(GREEN);
	 gotoxy(30,7);
	 cprintf(" 1.Generate result ");
	 gotoxy(30,8);
	 textbackground(CYAN);
	 cprintf(" 2.View result ");
	 gotoxy(30,9);
	 cprintf(" 3.Go Back ");
	 break;
      case 2:
	 gotoxy(30,8);
	 textbackground(GREEN);
	 cprintf(" 2.View result ");
	 textbackground(CYAN);
	 gotoxy(30,7);
	 cprintf(" 1.Generate result ");
	 gotoxy(30,9);
	 cprintf(" 3.Go Back ");
	 break;
      case 3:
	 textbackground(GREEN);
	 gotoxy(30,9);
	 cprintf(" 3.Go Back ");
	 textbackground(CYAN);
	 gotoxy(30,7);
	 cprintf(" 1.Generate result ");
	 gotoxy(30,8);
	 cprintf(" 2.View result ");
	 break;
   }
}

void result()
{
   int roll,flag=0,i;
   fp=fopen("student.txt","rb+");
   if(fp==NULL)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
   drawwindow("Result");
   gotoxy(3,3);
   puts("Enter Roll No.");
   gotoxy(3,4);
   textbackground(BLUE);
   cprintf("     ");
   _setcursortype(2);
   gotoxy(4,4);
   scanf("%d",&roll);
   _setcursortype(0);

   textbackground(BLUE);
   gotoxy(5,6);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(5,7);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(5,7);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      if(roll==s.roll)
      {
	 showResult();
	 flag=1;
	 break;
      }
      fseek(fp,1,SEEK_CUR);
   }

   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Record not found");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
}

void showResult()
{
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,1);
   printf("\xB2\xB2\xB2 Mark Sheet \xB2\xB2\xB2");
   gotoxy(20,2);
   puts("Name");
   gotoxy(35,2);
   textbackground(BROWN);
   cprintf("                    ");
   gotoxy(36,2);
   puts(s.name);
   gotoxy(20,4);
   puts("Father's Name");
   gotoxy(35,4);
   cprintf("                    ");
   gotoxy(36,4);
   puts(s.fname);
   gotoxy(20,6);
   puts("Roll No.");
   gotoxy(35,6);
   cprintf("     ");
   gotoxy(36,6);
   printf("%d",s.roll);
   gotoxy(20,8);
   puts("Enrollment No.");
   gotoxy(35,8);
   cprintf("                    ");
   gotoxy(36,8);
   puts(s.enroll);
   gotoxy(10,10);
   puts("============================================================");
   gotoxy(11,11);
   puts("Subject");
   gotoxy(22,11);
   puts("Full Marks");
   gotoxy(36,11);
   puts("Pass Marks");
   gotoxy(50,11);
   puts("Marks Obtained");
   gotoxy(10,12);
   puts("============================================================");
   gotoxy(12,13);
   puts("Physics");
   gotoxy(25,13);
   puts("100");
   gotoxy(40,13);
   puts("30");
   gotoxy(55,13);
   printf("%d",s.phy);
   gotoxy(10,14);
   puts("============================================================");
   gotoxy(12,15);
   puts("Chemistry");
   gotoxy(25,15);
   puts("100");
   gotoxy(40,15);
   puts("30");
   gotoxy(55,15);
   printf("%d",s.chem);
   gotoxy(10,16);
   puts("============================================================");
   gotoxy(12,17);
   puts("Mathematics");
   gotoxy(25,17);
   puts("100");
   gotoxy(40,17);
   puts("30");
   gotoxy(55,17);
   printf("%d",s.math);
   gotoxy(10,18);
   puts("============================================================");
   gotoxy(12,19);
   puts("Hindi");
   gotoxy(25,19);
   puts("100");
   gotoxy(40,19);
   puts("30");
   gotoxy(55,19);
   printf("%d",s.hindi);
   gotoxy(10,20);
   puts("============================================================");
   gotoxy(12,21);
   puts("English");
   gotoxy(25,21);
   puts("100");
   gotoxy(40,21);
   puts("30");
   gotoxy(55,21);
   printf("%d",s.english);
   fclose(fp);
   while(!kbhit())
   {
      gotoxy(30,22);
      printf("  < Press any key >  ");delay(500);
      gotoxy(30,22);
      printf(" << Press any key >> ");delay(500);
      gotoxy(30,22);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
   return;
}


void list()
{
   int i=0;
   fp=fopen("student.txt","rb+");
   if(fp==NULL)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,3);
   printf("\xB2\xB2\xB2 List of Students \xB2\xB2\xB2");
   textbackground(CYAN);
   gotoxy(7,5);
   cprintf(" Name ");
   gotoxy(20,5);
   cprintf(" Father's Name ");
   gotoxy(40,5);
   cprintf(" Roll ");
   gotoxy(48,5);
   cprintf(" Enrollment No.");
   gotoxy(65,5);
   cprintf(" Mobile No.");

   rewind(fp);
   while(fread(&s,sizeof(s),1,fp)>0)
   {
      printList(i);
      i++;
      fseek(fp,1,SEEK_CUR);
   }
   while(!kbhit())
   {
      gotoxy(25,20);
      printf("  < Press any key >  ");delay(500);
      gotoxy(25,20);
      printf(" << Press any key >> ");delay(500);
      gotoxy(25,20);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
}

void printList(int i)
{
   gotoxy(5,6+i);
   puts(s.name);
   gotoxy(20,6+i);
   puts(s.fname);
   gotoxy(40,6+i);
   printf("%d",s.roll);
   gotoxy(48,6+i);
   puts(s.enroll);
   gotoxy(65,6+i);
   puts(s.mob);
}

void editSelect(int click)
{
   if(click==1)
   {
      if(choice==6)
	 choice=1;
      else
	 choice++;
   }
   if(click==-1)
   {
      if(choice==1)
	 choice=6;
      else
	 choice--;
   }
   switch(choice)
   {
      case 1:
	 gotoxy(30,5);
	 textbackground(GREEN);
	 cprintf(" 1.Name ");
	 textbackground(CYAN);
	 gotoxy(30,6);
	 cprintf(" 2.Father's Name ");
	 gotoxy(30,7);
	 cprintf(" 3.Mother's Name ");
	 gotoxy(30,8);
	 cprintf(" 4.Date of Birth ");
	 gotoxy(30,9);
	 cprintf(" 5.Mobile No. ");
	 gotoxy(30,10);
	 cprintf(" 6.Address ");
	 break;
      case 2:
	 textbackground(GREEN);
	 gotoxy(30,6);
	 cprintf(" 2.Father's Name ");
	 textbackground(CYAN);
	 gotoxy(30,5);
	 cprintf(" 1.Name ");
	 gotoxy(30,7);
	 cprintf(" 3.Mother's Name ");
	 gotoxy(30,8);
	 cprintf(" 4.Date of Birth ");
	 gotoxy(30,9);
	 cprintf(" 5.Mobile No. ");
	 gotoxy(30,10);
	 cprintf(" 6.Address ");
	 break;
      case 3:
	 textbackground(GREEN);
	 gotoxy(30,7);
	 cprintf(" 3.Mother's Name ");
	 textbackground(CYAN);
	 gotoxy(30,5);
	 cprintf(" 1.Name ");
	 gotoxy(30,6);
	 cprintf(" 2.Father's Name ");
	 gotoxy(30,8);
	 cprintf(" 4.Date of Birth ");
	 gotoxy(30,9);
	 cprintf(" 5.Mobile No. ");
	 gotoxy(30,10);
	 cprintf(" 6.Address ");
	 break;
      case 4:
	 textbackground(GREEN);
	 gotoxy(30,8);
	 cprintf(" 4.Date of Birth ");
	 textbackground(CYAN);
	 gotoxy(30,5);
	 cprintf(" 1.Name ");
	 gotoxy(30,6);
	 cprintf(" 2.Father's Name ");
	 gotoxy(30,7);
	 cprintf(" 3.Mother's Name ");
	 gotoxy(30,9);
	 cprintf(" 5.Mobile No. ");
	 gotoxy(30,10);
	 cprintf(" 6.Address ");
	 break;
      case 5:
	 textbackground(GREEN);
	 gotoxy(30,9);
	 cprintf(" 5.Mobile No. ");
	 textbackground(CYAN);
	 gotoxy(30,5);
	 cprintf(" 1.Name ");
	 gotoxy(30,6);
	 cprintf(" 2.Father's Name ");
	 gotoxy(30,7);
	 cprintf(" 3.Mother's Name ");
	 gotoxy(30,8);
	 cprintf(" 4.Date of Birth ");
	 gotoxy(30,10);
	 cprintf(" 6.Address ");
	 break;
      case 6:
	 textbackground(GREEN);
	 gotoxy(30,10);
	 cprintf(" 6.Address ");
	 textbackground(CYAN);
	 gotoxy(30,5);
	 cprintf(" 1.Name ");
	 gotoxy(30,6);
	 cprintf(" 2.Father's Name ");
	 gotoxy(30,7);
	 cprintf(" 3.Mother's Name ");
	 gotoxy(30,8);
	 cprintf(" 4.Date of Birth ");
	 gotoxy(30,9);
	 cprintf(" 5.Mobile No. ");
	 break;
   }
}

void searchSelect(int click)
{
   if(click==1)
   {
      if(choice==5)
	 choice=1;
      else
	 choice++;
   }
   if(click==-1)
   {
      if(choice==1)
	 choice=5;
      else
	 choice--;
   }
   switch(choice)
   {
      case 1:
	 textbackground(GREEN);
	 gotoxy(30,8);
	 cprintf(" 1. Search by Name ");
	 textbackground(CYAN);
	 gotoxy(30,10);
	 cprintf(" 2. Search by Roll No.");
	 gotoxy(30,12);
	 cprintf(" 3. Search by Enrollment No.");
	 gotoxy(30,14);
	 cprintf(" 4. Search by Mobile No.");
	 gotoxy(30,16);
	 cprintf(" 5. Search by Aadhar No.");
	 break;
      case 2:
	 textbackground(GREEN);
	 gotoxy(30,10);
	 cprintf(" 2. Search by Roll No.");
	 textbackground(CYAN);
	 gotoxy(30,8);
	 cprintf(" 1. Search by Name ");
	 gotoxy(30,12);
	 cprintf(" 3. Search by Enrollment No.");
	 gotoxy(30,14);
	 cprintf(" 4. Search by Mobile No.");
	 gotoxy(30,16);
	 cprintf(" 5. Search by Aadhar No.");
	 break;
      case 3:
	 textbackground(GREEN);
	 gotoxy(30,12);
	 cprintf(" 3. Search by Enrollment No.");
	 textbackground(CYAN);
	 gotoxy(30,8);
	 cprintf(" 1. Search by Name ");
	 gotoxy(30,10);
	 cprintf(" 2. Search by Roll No.");
	 gotoxy(30,14);
	 cprintf(" 4. Search by Mobile No.");
	 gotoxy(30,16);
	 cprintf(" 5. Search by Aadhar No.");
	 break;
      case 4:
	 textbackground(GREEN);
	 gotoxy(30,14);
	 cprintf(" 4. Search by Mobile No.");
	 textbackground(CYAN);
	 gotoxy(30,8);
	 cprintf(" 1. Search by Name ");
	 gotoxy(30,10);
	 cprintf(" 2. Search by Roll No.");
	 gotoxy(30,12);
	 cprintf(" 3. Search by Enrollment No.");
	 gotoxy(30,16);
	 cprintf(" 5. Search by Aadhar No.");
	 break;
      case 5:
	 textbackground(GREEN);
	 gotoxy(30,16);
	 cprintf(" 5. Search by Aadhar No.");
	 textbackground(CYAN);
	 gotoxy(30,8);
	 cprintf(" 1. Search by Name ");
	 gotoxy(30,10);
	 cprintf(" 2. Search by Roll No.");
	 gotoxy(30,12);
	 cprintf(" 3. Search by Enrollment No.");
	 gotoxy(30,14);
	 cprintf(" 4. Search by Mobile No.");
	 break;
   }
   return;
}

void menuSelect(int click)
{
   if(click==1)
   {
      if(choice==7)
	 choice=1;
      else
	 choice++;
   }
   if(click==-1)
   {
      if(choice==1)
	 choice=7;
      else
	 choice--;
   }
   switch(choice)
   {
      case 1:
	 textbackground(GREEN);
	 gotoxy(2,1);
	 cprintf(" Admission ");
	 gotoxy(14,1);
	 textbackground(CYAN);
	 cprintf(" Details ");
	 gotoxy(24,1);
	 cprintf(" Edit ");
	 gotoxy(31,1);
	 cprintf(" Delete ");
	 gotoxy(41,1);
	 cprintf(" Result ");
	 gotoxy(50,1);
	 cprintf(" List ");
	 gotoxy(57,1);
	 cprintf(" Logout ");
	 break;
      case 2:
	 gotoxy(14,1);
	 textbackground(GREEN);
	 cprintf(" Details ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Admission ");
	 gotoxy(24,1);
	 cprintf(" Edit ");
	 gotoxy(31,1);
	 cprintf(" Delete ");
	 gotoxy(41,1);
	 cprintf(" Result ");
	 gotoxy(50,1);
	 cprintf(" List ");
	 gotoxy(57,1);
	 cprintf(" Logout ");
	 break;
      case 3:
	 textbackground(GREEN);
	 gotoxy(24,1);
	 cprintf(" Edit ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Admission ");
	 gotoxy(14,1);
	 cprintf(" Details ");
	 gotoxy(31,1);
	 cprintf(" Delete ");
	 gotoxy(41,1);
	 cprintf(" Result ");
	 gotoxy(50,1);
	 cprintf(" List ");
	 gotoxy(57,1);
	 cprintf(" Logout ");
	 break;
      case 4:
	 textbackground(GREEN);
	 gotoxy(31,1);
	 cprintf(" Delete ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Admission ");
	 gotoxy(14,1);
	 cprintf(" Details ");
	 gotoxy(24,1);
	 cprintf(" Edit ");
	 gotoxy(41,1);
	 cprintf(" Result ");
	 gotoxy(50,1);
	 cprintf(" List ");
	 gotoxy(57,1);
	 cprintf(" Logout ");
	 break;
      case 5:
	 textbackground(GREEN);
	 gotoxy(41,1);
	 cprintf(" Result ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Admission ");
	 gotoxy(14,1);
	 cprintf(" Details ");
	 gotoxy(24,1);
	 cprintf(" Edit ");
	 gotoxy(31,1);
	 cprintf(" Delete ");
	 gotoxy(50,1);
	 cprintf(" List ");
	 gotoxy(57,1);
	 cprintf(" Logout ");
	 break;
      case 6:
	 textbackground(GREEN);
	 gotoxy(50,1);
	 cprintf(" List ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Admission ");
	 gotoxy(14,1);
	 cprintf(" Details ");
	 gotoxy(24,1);
	 cprintf(" Edit ");
	 gotoxy(31,1);
	 cprintf(" Delete ");
	 gotoxy(41,1);
	 cprintf(" Result ");
	 gotoxy(57,1);
	 cprintf(" Logout ");
	 break;
      case 7:
	 textbackground(GREEN);
	 gotoxy(57,1);
	 cprintf(" Logout ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Admission ");
	 gotoxy(14,1);
	 cprintf(" Details ");
	 gotoxy(24,1);
	 cprintf(" Edit ");
	 gotoxy(31,1);
	 cprintf(" Delete ");
	 gotoxy(41,1);
	 cprintf(" Result ");
	 gotoxy(50,1);
	 cprintf(" List ");
   }
}

void okSelect(int click)
{
   if(click==1)
   {
      if(choice==2)
	 choice=1;
      else
	 choice++;
   }
   if(click==-1)
   {
      if(choice==1)
	 choice=2;
      else
	 choice--;
   }
   switch(choice)
   {
      case 1:
	 gotoxy(3,8);
	 textbackground(GREEN);
	 cprintf(" Ok ");
	 gotoxy(11,8);
	 textbackground(CYAN);
	 cprintf(" Cancel ");
	 break;
      case 2:
	 gotoxy(3,8);
	 textbackground(CYAN);
	 cprintf(" Ok ");
	 gotoxy(11,8);
	 textbackground(GREEN);
	 cprintf(" Cancel ");
   }
}

void sLogin()
{
   char enroll[13],pass[15];
   int click;
   fp=fopen("student.txt","rb+");
   if(fp==NULL)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      return;
   }
   window(25,6,45,20);
   textbackground(BROWN);
   clrscr();
   gotoxy(2,2);
   printf("Enter enrollment No.");
   textbackground(BLUE);
   gotoxy(2,3);
   cprintf("                  ");
   gotoxy(2,5);
   printf("Enter Password");
   gotoxy(2,6);
   cprintf("                  ");
   gotoxy(3,8);
   textbackground(CYAN);
   cprintf(" Ok ");
   gotoxy(11,8);
   cprintf(" Cancel ");
   gotoxy(3,3);
   _setcursortype(2);
   fflush(stdin);
   gets(enroll);
   gotoxy(3,6);
   fflush(stdin);
   gets(pass);
   gotoxy(3,8);
   textbackground(GREEN);
   cprintf(" Ok ");
   choice=1;
   _setcursortype(0);
   lineno160:
   getkey();
   switch(ch)
   {
      case LEFT:
	 click=-1;
	 okSelect(click);
	 goto lineno160;
      case RIGHT:
	 click=1;
	 okSelect(click);
	 goto lineno160;
      default:
	 if(ch==13)
	 {
	    switch(choice)
	    {
	       case 1:
		  stLogin(enroll,pass);
		  return;
	       case 2:
		  fclose(fp);
		  return;
	    }
	 }
	 else
	    goto lineno160;
   }
}

void stLogin(char enroll[13] , char pass[15])
{
   int i,flag=0;
   FILE *fp1;
   fp1=fopen("stid.txt","rb+");
   if(fp1==NULL)
   {
      drawwindow( "Notification");
      gotoxy(5,3);
      printf("Server problem. try again...");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();
      fclose(fp);
      fclose(fp1);
      return;
   }

   textbackground(BROWN);
   gotoxy(2,10);textcolor(RED+BLINK);cprintf("Loading...");
   gotoxy(2,11);
   textbackground(WHITE);
   for(i=0;i<15;i++)
   {textcolor(WHITE);cprintf("%c",219);}
   gotoxy(2,11);
   textbackground(GREEN);
   for(i=0;i<15;i++)
   {delay(150);textcolor(GREEN);cprintf("%c",219);}
   textcolor(WHITE);

   rewind(fp1);
   while(fread(&id,sizeof(id),1,fp1)>0)
   {
      if(strcmp(enroll,id.user)==0 && strcmp(pass,id.pass)==0)
      {
	 rewind(fp);
	 while(fread(&s,sizeof(s),1,fp)>0)
	 {
	    if(strcmp(id.user,s.enroll)==0)
	    {
	       sMenu();
	       flag=1;
	       break;
	    }
	    fseek(fp,1,SEEK_CUR);
	 }
	 break;
      }
      fseek(fp1,1,SEEK_CUR);
   }
   fclose(fp);
   fclose(fp1);
   if(flag==0)
   {
      drawwindow("Notification");
      gotoxy(5,3);
      printf("Invalid enrollment");
      gotoxy(5,4);
      puts("number or password.");
      while(!kbhit())
      {
	 gotoxy(2,7);
	 printf("  < Press any key >  ");delay(500);
	 gotoxy(2,7);
	 printf(" << Press any key >> ");delay(500);
	 gotoxy(2,7);
	 printf("<<< Press any key >>>");delay(500);
      }
      getch();

      return;
   }

}

void sMenu()
{
   int click,i, add;
   lineno270:
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   textbackground(GREEN);
   gotoxy(2,1);
   cprintf(" Dashboard ");
   choice =1;
   gotoxy(14,1);
   textbackground(CYAN);
   cprintf(" Personal Detail ");
   gotoxy(32,1);
   cprintf(" Address ");
   gotoxy(42,1);
   cprintf(" Fee Detail ");
   gotoxy(55,1);
   cprintf(" Marksheet ");
   gotoxy(67,1);
   cprintf(" Logout ");
   getch();
   lineno280:
   getkey();
   switch(ch)
   {
      case RIGHT:
	 click=1;
	 sMenuSelect(click);
	 goto lineno280;
      case LEFT:
	 click=-1;
	 sMenuSelect(click);
	 goto lineno280;
      case ENTER:
	 switch(choice)
	 {
	    case 1:
	       sDashboard();
	       goto lineno270;
	    case 2:
	       add = 0;
	       show(add);
	       goto lineno270;
	    case 3:
	       showAddress();
	       goto lineno270;
	    case 4:
	       feeDetail();
	       goto lineno270;
	    case 5:
	       showResult();
	       goto lineno270;
	    case 6:
		  logout();
		  return;
	 }
      default:
	 goto lineno280;
   }

}

void sDashboard()
{
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();
   gotoxy(30,2);
   printf("\xB2\xB2\xB2 Welcome Mr. %s \xB2\xB2\xB2", s.name);
   gotoxy(20,4);
   printf("Name");
   gotoxy(35,4);
   textbackground(BROWN);
   cprintf("                         ");
   gotoxy(36,4);
   puts(s.name);
   gotoxy(20,6);
   printf("Date of Birth");
   gotoxy(36,6);printf("DD"); gotoxy(41,6);printf("MM");  gotoxy(46,6);printf("YYYY");
   gotoxy(35,7);cprintf("    "); gotoxy(40,7);cprintf("    "); gotoxy(45,7);cprintf("      ");
   gotoxy(36,7);printf("%d",s.ddd);gotoxy(41,7);printf("%d",s.dmm);gotoxy(46,7);printf("%d",s.dyyyy);
   gotoxy(20,9);
   printf("Enrollment No.");
   gotoxy(35,9);
   cprintf("               ");
   gotoxy(36,9);
   puts(s.enroll);
   gotoxy(20,11);
   puts("Mobile No.");
   gotoxy(35,11);
   cprintf("            ");
   gotoxy(36,11);
   puts(s.mob);
   gotoxy(20,13);
   printf("Aadhar No.");
   gotoxy(35,13);
   cprintf("              ");
   gotoxy(36,13);
   puts(s.aadhar);

   while(!kbhit())
   {
      gotoxy(20,15);
      printf("  < Press any key >  ");delay(500);
      gotoxy(20,15);
      printf(" << Press any key >> ");delay(500);
      gotoxy(20,15);
      printf("<<< Press any key >>>");delay(500);
   }
   getch();
}

void feeDetail()
{

}

void sMenuSelect(click)
{
   if(click == 1)
   {
      if(choice == 6)
	 choice = 1;
      else
	 choice++;
   }
   else if(click == -1)
   {
      if(choice == 1)
	 choice = 6;
      else
	 choice--;
   }

   switch(choice)
   {
      case 1:
	 textbackground(GREEN);
	 gotoxy(2,1);
	 cprintf(" Dashboard ");
	 gotoxy(14,1);
	 textbackground(CYAN);
	 cprintf(" Personal Detail ");
	 gotoxy(32,1);
	 cprintf(" Address ");
	 gotoxy(42,1);
	 cprintf(" Fee Detail ");
	 gotoxy(55,1);
	 cprintf(" Marksheet ");
	 gotoxy(67,1);
	 cprintf(" Logout ");
	 break;
      case 2:
	 gotoxy(14,1);
	 textbackground(GREEN);
	 cprintf(" Personal Detail ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Dashboard ");
	 gotoxy(32,1);
	 cprintf(" Address ");
	 gotoxy(42,1);
	 cprintf(" Fee Detail ");
	 gotoxy(55,1);
	 cprintf(" Marksheet ");
	 gotoxy(67,1);
	 cprintf(" Logout ");
	 break;
      case 3:
	 textbackground(GREEN);
	 gotoxy(32,1);
	 cprintf(" Address ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Dashboard ");
	 gotoxy(14,1);
	 cprintf(" Personal Detail ");
	 gotoxy(42,1);
	 cprintf(" Fee Detail ");
	 gotoxy(55,1);
	 cprintf(" Marksheet ");
	 gotoxy(67,1);
	 cprintf(" Logout ");
	 break;
      case 4:
	 textbackground(GREEN);
	 gotoxy(42,1);
	 cprintf(" Fee Detail ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Dashboard ");
	 gotoxy(14,1);
	 cprintf(" Personal Detail ");
	 gotoxy(32,1);
	 cprintf(" Address ");
	 gotoxy(55,1);
	 cprintf(" Marksheet ");
	 gotoxy(67,1);
	 cprintf(" Logout ");
	 break;
      case 5:
	 textbackground(GREEN);
	 gotoxy(55,1);
	 cprintf(" Marksheet ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Dashboard ");
	 gotoxy(14,1);
	 cprintf(" Personal Detail ");
	 gotoxy(32,1);
	 cprintf(" Address ");
	 gotoxy(42,1);
	 cprintf(" Fee Detail ");
	 gotoxy(67,1);
	 cprintf(" Logout ");
	 break;
      case 6:
	 textbackground(GREEN);
	 gotoxy(67,1);
	 cprintf(" Logout ");
	 textbackground(CYAN);
	 gotoxy(2,1);
	 cprintf(" Dashboard ");
	 gotoxy(14,1);
	 cprintf(" Personal Detail ");
	 gotoxy(32,1);
	 cprintf(" Address ");
	 gotoxy(42,1);
	 cprintf(" Fee Detail ");
	 gotoxy(55,1);
	 cprintf(" Marksheet ");
	 break;
   }
}

void drawwindow(char head[30])
{
   textbackground(7);
   textcolor(0);
   window(28-3,8-2,52+3,8-2); //x1=28,y1=8,x2=52,y2=18
	//x1   y1  x2   y1
   clrscr();
   gotoxy(((52+3)-(28-3)+3-strlen(head))/2,1);
     //     x2     x1
   printf("%s",head);
   textbackground(RED);
   textcolor(WHITE);
   window(28-3,8-1,52+3,18+1);
     //   x1  y1    x2   y2
   clrscr();
   drawbox(28-3, 8-1, 52+3, 18+1);
       //  x1    y1   x2    y2
   window(28,8,52+1,18);
   //     x1,y1,x2,y2
}

void drawbox(int left, int top, int right, int bottom)
{
   int i;
   for(i=0; i<right-left-1; i++)
   {
      if(i==0)
	 printf(" \332");
      else if(i==right-left-2)
	 printf("\277");
      else
	 printf("\304");
   }

   for(i=0; i<bottom-top-1; i++)
   {
      gotoxy(2,i+2);
      printf("\263");
     gotoxy(right-left,i+2);
     printf("\263");
   }

   gotoxy(1,bottom-top+1);

   for(i=0; i<right-left-1; i++)
   {
      if(i==0)
	 printf(" \300");
      else if(i==right-left-2)
	 printf("\331");
      else
	 printf("\304");
   }
   //gotoxy(((right+3)-(left-3)+3-strlen("Notification"))/2,1);
   //printf("Notification");
}


void loginSelect(int click)
{
   if(click==1)
   {
      if(choice==3)
	 choice=1;
      else
	 choice++;
   }
   if(click==-1)
   {
      if(choice==1)
	 choice =3;
      else
	 choice--;
   }
   switch(choice)
   {
      case 1:
	 gotoxy(35,7);
	 textbackground(GREEN);
	 cprintf("1. HOD Login ");
	 gotoxy(35,8);
	 textbackground(CYAN);
	 cprintf("2. Student Login ");
	 gotoxy(35,9);
	 cprintf("3. Go Back ");
	 break;
      case 2:
	 gotoxy(35,8);
	 textbackground(GREEN);
	 cprintf("2. Student Login ");
	 gotoxy(35,7);
	 textbackground(CYAN);
	 cprintf("1. HOD Login ");
	 gotoxy(35,9);
	 cprintf("3. Go Back ");
	 break;
      case 3:
	 textbackground(GREEN);
	 gotoxy(35,9);
	 cprintf("3. Go Back ");
	 gotoxy(35,7);
	 textbackground(CYAN);
	 cprintf("1. HOD Login ");
	 gotoxy(35,8);
	 cprintf("2. Student Login ");
   }
}

void regs()
{
   struct Id t;
   char temp[5];
   int pass;

   fp=fopen("student.txt","rb+");
   if(fp==NULL)
   {
      clrscr();
      gotoxy(20, 4);
      printf("Server preblem. Please try again later...");
      gotoxy(20, 5);
      printf("Press any key to continue...");
      getch();
   }
   ch = -1;
   byRoll();
   if(ch==1)
      return;
   fp=fopen("stid.txt","ab+");
   window(2,2,79,23);
   textbackground(BLUE);
   clrscr();

   strcpy(id.user,s.enroll);

   rewind(fp);
   while(fread(&t,sizeof(t),1,fp)>0)
   {
      fflush(stdin);
      if(strcmp(t.user,id.user)==0)
      {
	 gotoxy(10,5);
	 puts("You have already register for student login.");
	 gotoxy(10,6);
	 printf("Your enrollment No. is : ");puts(t.user);
	 gotoxy(10,7);
	 printf("Your password is : ");puts(t.pass);
	 gotoxy(10,8);
	 puts("Have a note of it.  Please!!!");

	 while(!kbhit())
	 {
	    gotoxy(20,10);
	    printf("  < Press any key >  ");delay(500);
	    gotoxy(20,10);
	    printf(" << Press any key >> ");delay(500);
	    gotoxy(20,10);
	    printf("<<< Press any key >>>");delay(500);
	 }
	 getch();
	 fclose(fp);
	 return;
      }
      fseek(fp,1,SEEK_CUR);
   }

   lineno3330:        // Label for password
   strcpy(id.pass,"SiteCse");
   pass=rand();
   if(pass<100 || pass>=1000)
      goto lineno3330;
   itoa(pass,temp,10);
   strcat(id.pass,temp);

   rewind(fp);
   while(fread(&t,sizeof(t),1,fp)>0)
   {				    // Checking password
      if(strcmp(id.pass,t.pass)==0)
	 goto lineno3330;
      fflush(stdin);
      fseek(fp,1,SEEK_CUR);
   }
   id.tab = '\t';

   fwrite(&id,sizeof(id),1,fp);
   fprintf(fp,"\n");
   fclose(fp);

   gotoxy(10,5);
   puts("You have successfully register for student login.");
   gotoxy(10,6);
   printf("Your enrollment No. is : %s",id.user);
   gotoxy(10,7);
   printf("Your password is : %s",id.pass);
   gotoxy(10,8);
   puts("Have a note of it.   Please!!!");

   while(!kbhit())
   {
      gotoxy(20,10);
      printf("  < Press any key >  ");delay(500);
      gotoxy(20,10);
      printf(" << Press any key >> ");delay(500);
      gotoxy(20,10);
      printf("<<< Press any key >>");delay(500);
   }
   getch();
}

void about()
{
   gotoxy(20,5);
   cprintf("You are in about function");
   getch();
}

void select(int click)
{
   if(click==1)
   {
      if(choice==4)
	 choice=1;
      else
	 choice++;
   }
   else
   {
      if(choice==1)
	 choice=4;
      else
	 choice--;
   }
   switch(choice)
   {
      case 1:
	 gotoxy(2,1);
	 textbackground(GREEN);
	 cprintf(" Login ");
	 textbackground(CYAN);
	 gotoxy(10,1);
	 cprintf(" Registraton ");
	 gotoxy(24,1);
	 cprintf(" About ");
	 gotoxy(32,1);
	 cprintf(" Exit ");
	 break;
      case 2:
	 textbackground(GREEN);
	 gotoxy(10,1);
	 cprintf(" Registraton ");
	 gotoxy(2,1);
	 textbackground(CYAN);
	 cprintf(" Login ");
	 gotoxy(24,1);
	 cprintf(" About ");
	 gotoxy(32,1);
	 cprintf(" Exit ");
	 break;
      case 3:
	 textbackground(GREEN);
	 gotoxy(24,1);
	 cprintf(" About ");
	 gotoxy(2,1);
	 textbackground(CYAN);
	 cprintf(" Login ");
	 gotoxy(10,1);
	 cprintf(" Registraton ");
	 gotoxy(32,1);
	 cprintf(" Exit ");
	 break;
      case 4:
	 textbackground(GREEN);
	 gotoxy(32,1);
	 cprintf(" Exit ");
	 gotoxy(2,1);
	 textbackground(CYAN);
	 cprintf(" Login ");
	 gotoxy(10,1);
	 cprintf(" Registraton ");
	 gotoxy(24,1);
	 cprintf(" About ");
	 break;
   }
}

void getkey()
{
   lineno50:
   fflush(stdin);
   ch = getch();
   if(ch == UP || ch==LEFT || ch==RIGHT || ch==DOWN || ch==13)
      return;
   else
      goto lineno50;
}