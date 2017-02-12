#include <windows.h>
#include <stdio.h>                   //contains printf,scanf etc
#include <conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
void addbooks();
void deletebooks();
void mainmenu();
void thankyou();
int checkid(int t);
void viewbooks();
void searchbooks();
void issuebooks();
void returnfunc();
int getdata();
void studentmenu();
int s;
char ch;
FILE *fp,*ft,*fs,*fh,*fd;
struct student
{
    int rollnumber;
    char stname[20];
    char branch[20];
    char section[1];
    int sem;
    int id;
    char duedate[30];
    char name[20];
    };
struct student b;
struct books
{
    int id;
    char stname[20];
    char name[20];
    char author[20];
    int quantity;
    float price;
    int count;
    int rackno;
    char *cat;
    char duedate[30];
};
struct books a ;
void mainmenu(){
    system("cls");
       //	textbackground(13);
	int i;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	//show_mouse();
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Issue Books");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. View Book list");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Close Application");
	gotoxy(20,19);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,21);

     printf("Enter your choice:");
     switch(getch())
	{
		case '1':
		addbooks();
		break;
	 case '2':
		deletebooks();
		break;
    case '3':
		searchbooks();
	    break;

	case '4':
		issuebooks();
	    break;
    case '5':
		viewbooks();
		break;
    case '6':
        thankyou();
		break;
    default:
		{
		gotoxy(10,23);
		printf("\aWrong Entry!!Please re-entered correct option");
		if(getch())
		mainmenu();
		}

    }
}
void stringCopy(char str1[],char str2[]){ //for copying
    int i=0;

    while(str1[i]!='\0'){
         str2[i] = str1[i];
         i++;
    }

    str2[i]='\0';
}
void thankyou(){ //exit screen display
    system("cls");
    gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(46,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(46,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(46,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(46,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(46,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(46,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(46,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(22,9);
	printf("THANK YOU!!!!!");
	gotoxy(0,30);

}
int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;  //returns 0 if book exits
      return 1; //return 1 if it not
}
int checkidissue(int t)  //check whether the book is exist in library or not
{
    fh=fopen("inter.dat","ab+");
	rewind(fh);
	while(fread(&a,sizeof(a),1,fh)==1)
	if(a.id==t)
	return 0;  //returns 0 if book exits
      return 1; //return 1 if it not
}
int getdata() //getting data for adding information of books
{
	int t;
	gotoxy(20,3);printf("Enter the Information Below");
	gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(46,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(46,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(46,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(46,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(46,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(46,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(46,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,5);
	printf("Category:");
	gotoxy(31,5);
	printf("%s",catagories[s-1]);
	gotoxy(21,6);
	printf("Book ID:\t");
	gotoxy(30,6);
	scanf("%d",&t);
	if(checkid(t) == 0|| checkidissue(t)==0) //checking if book alerady exist or not
	{
		gotoxy(21,13);
		printf("\aThe book id already exists\a");
		getch();
		mainmenu();
		return 0;
	}
	a.id=t;
	a.quantity=1;
	gotoxy(21,7);
	printf("Book Name:");gotoxy(33,7);
	scanf("%s",a.name);
	gotoxy(21,8);
	printf("Author:");gotoxy(30,8);
	scanf("%s",a.author);
	gotoxy(21,9);
	/* printf("Quantity:");gotoxy(31,9);
	scanf("%d",&a.quantity); */
	gotoxy(21,10);
	printf("Price:");gotoxy(28,10);
	scanf("%f",&a.price);
	gotoxy(21,11);
	printf("Rack No:");gotoxy(30,11);
	scanf("%d",&a.rackno);
	return 1;
}
void addbooks(){ //for adding books
     system("cls");
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CATAGORIES OF BOOKS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	//show_mouse();
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Civil");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Architecture");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
	gotoxy(20,19);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,20);
	printf("Enter your choice");
	scanf("%d",&s);
    if(s==7)
        mainmenu();
    system("cls");
    fp=fopen("chinesh.dat","ab+");
    if(getdata()==1)
        {
    a.cat=catagories[s-1];
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	gotoxy(21,14);
	printf("The record is sucessfully saved");
	gotoxy(21,15);
	printf("Save any more?(y / n):");
	if(getch()=='n')
	    mainmenu();
	else
	    system("cls");
	    addbooks();
    }
}
void deletebooks(){
    int findbook;
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	gotoxy(10,5);
	printf("Enter the Book ID to  delete:");
	scanf("%d",&d);
	fp=fopen("chinesh.dat","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	    if(a.id==d)
	    {

		gotoxy(10,7);
		printf("The book record is available");
		gotoxy(10,8);
		printf("Book name is %s",a.name);
		gotoxy(10,9);
		printf("Rack No. is %d",a.rackno);
		findbook='t';
	    }
	}
	if(findbook!='t')
	{
	    gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    mainmenu();
	}
	if(findbook=='t' )
	{
	    gotoxy(10,10);
	    printf("Do you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
		ft=fopen("test.dat","wb+");  //temporary file for delete
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
		    if(a.id!=d)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
		    }                              //we want to delete
		}
		fclose(ft);
		fclose(fp);
		remove("chinesh.dat");
		rename("test.dat","chinesh.dat"); //copy all item from temporary file to fp except that
		fp=fopen("chinesh.dat","rb+");    //we want to delete
		if(findbook=='t')
		{
		    gotoxy(10,10);
		    printf("The record is sucessfully deleted");
		    gotoxy(10,11);
		    printf("Delete another record?(Y/N)");
		}
	    }
	else
	mainmenu();
	fflush(stdin);
	another=getch();
	}
	}
    gotoxy(10,15);
    mainmenu();
}
void viewbooks(){
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;
    fp=fopen("chinesh.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
	gotoxy(3,j);
	printf("%s",a.cat);
	gotoxy(16,j);
	printf("%d",a.id);
	gotoxy(22,j);
	printf("%s",a.name);
	gotoxy(36,j);
	printf("%s",a.author);
	gotoxy(50,j);
	printf("%d",a.quantity);
	gotoxy(57,j);
	printf("%.2f",a.price);
	gotoxy(69,j);
	printf("%d",a.rackno);
	printf("\n\n");
	j++;
	i=i+a.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
}
void searchbooks(){
    int findbook;
    system("cls");
    gotoxy(10,4);
    printf("press 1 for search by ID \n");
    gotoxy(10,5);
    printf("press 2 for search by name \n");
    switch(getch()){
case '1':
     id();
    break;
case '2':
    name();

	break;
    }
}
int tii(void) //for time
{
    time_t now = time(NULL);
   struct tm *t = localtime(&now);
   printf( "%d:", t->tm_mon+1 );
   printf( "%d:", t->tm_mday );
   printf( "%d\n", t->tm_year+1900 );
   return 0;
}
void name(){ //for searching by name
    int findbook;
    system("cls");
    char d[10];
    system("cls");
	gotoxy(10,5);
	printf("NOTE:DO NOT PUT BLANKS IN THE NAME");
	printf("Enter the Book name to  search: ");
	scanf("%s",&d);
	fp=fopen("chinesh.dat","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	    if(strcmp(d,a.name)==0)
	    {

		//gotoxy(10,7);
		printf("The book record is available");
		//gotoxy(10,8);
		printf("Book name is %s \n",a.name);
		//gotoxy(10,9);
		printf("Book name is %d \n",a.id);
		//gotoxy(10,10);
		printf("Author name is %s \n",a.author);
		//gotoxy(10,11);
		printf("no. of books are %d \n",a.quantity);
		//gotoxy(10,12);
		printf("Price is %f \n",a.price);
		//gotoxy(10,13);
		printf("Rack No. is %d \n",a.rackno);
		findbook='t';
		printf("\n \n \n \n");

		//fflush(stdin);
	    }

	}
	fclose(fp);
	if(findbook!='t')
	{
	    //gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    mainmenu();
	}
}
void id(){ //for searching by id
    int d;
    int findbook;
    system("cls");
	gotoxy(10,5);
	printf("Enter the Book ID to  search:");
	scanf("%d",&d);
	fp=fopen("chinesh.dat","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	    if(a.id==d)
	    {
        system("cls");
		//gotoxy(10,7);
		printf("The book record is available");
		//gotoxy(10,8);
		printf("Book name is %s",a.name);
		//gotoxy(10,9);
		printf("Author name is %s",a.author);
		//gotoxy(10,10);
		printf("no. of books are %d",a.quantity);
		//gotoxy(10,11);
		printf("Price is %f",a.price);
		//gotoxy(10,12);
		printf("Rack No. is %d",a.rackno);
		findbook='t';
		//fflush(stdin);
	    }
	    fclose(fp);
	}
	if(findbook!='t')
	{
	    gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    mainmenu();
	}
}
int checkidi(int n)  //check whether the book is issued or not
{
	rewind(fs);
	while(fread(&b,sizeof(b),1,fs)==1)
	if(b.id==n)
	return 0;  //returns 0 if book already issued
      return 1; //return 1 if it not
}
int getbooks(){ //getting information about student to whom book is issued
    int n;
	gotoxy(20,3);printf("Enter the Information Below");
	gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(46,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(46,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(46,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(46,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(46,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(46,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(46,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,5);

	printf("Book ID:\t");
	gotoxy(30,6);
	scanf("%d",&n);
    fp=fopen("chinesh.dat","r");
	rewind(fp);
	//while(fread(&a,sizeof(a),1,fp)==1)
	/*if(n!=a.id){
            gotoxy(21,13);
		printf("\aThe book id does not present in library\a");
		getch();
		mainmenu();
	return 0;  //returns 0 if book exits
      return 1; //return 1 if it not
}*/
	if(checkidi(n) == 0)
	{
		gotoxy(21,13);
		printf("\aThe book id already issued\a");
		getch();
		mainmenu();
		return 0;
	}
	b.id=n;
	//a.quantity=1;
	gotoxy(21,7);
	printf("Student Name:");gotoxy(33,7);
	scanf("%s",&b.stname);
	gotoxy(21,8);
	printf("Rollnumber:");gotoxy(30,8);
	scanf("%d",&b.rollnumber);
	gotoxy(21,9);
	printf("Branch");gotoxy(31,9);
	scanf("%s",&b.branch);
	gotoxy(21,10);
	printf("semester");gotoxy(28,10);
	scanf("%d",&b.sem);
	gotoxy(21,11);
	printf("Section");gotoxy(30,11);
	scanf("%s",&b.section);
	printf("issued date is:");
		tii();
		gotoxy(21,13);
        printf("The BOOK of ID %d is issued",b.id);
        gotoxy(21,14);
        printf("return date is:");
        time_t now = time(NULL);
   struct tm *t = localtime(&now);

   int y = t->tm_year+1900;
   int m =t->tm_mon+1;
   int d = t->tm_mday;
      int skip=15;


   // Represent the date as struct tm.
   // The subtractions are necessary for historical reasons.
   struct tm  t1 = { 0 };
   t1.tm_mday = d;
   t1.tm_mon = m-1;
   t1.tm_year = y-1900;

   // Add 'skip' days to the date.
   t1.tm_mday += skip;
   mktime(&t1);

   // Print the date in ISO-8601 format.
   char buffer[30];
   strftime(buffer, 30, "%Y-%m-%d", &t1);
   puts(buffer);
        stringCopy(buffer,b.duedate);
        stringCopy(b.duedate,a.duedate);

    fp=fopen("chinesh.dat","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	    if(a.id==n)
        printf("Book name is %s",a.name);
        stringCopy(a.name,b.name);
		}
	    fclose(fp);


   fp=fopen("chinesh.dat","rb+");
	rewind(fp);


		while(fread(&a,sizeof(a),1,fp)==1)
		{
		    if(a.id==n) //getting problem here
		    {
		        fh=fopen("inter.dat","rb+");
		        fseek(fh,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,fh);
			fclose(fh);
		    }

		    if(a.id!=n)
		    {
            rewind(fp);
            ft=fopen("test.dat","wb+");  //temporary file for delete
			fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
		    }                              //we want to delete
		}
		fclose(ft);
		fclose(fp);
		remove("chinesh.dat");
		rename("test.dat","chinesh.dat"); //copy all item from temporary file to fp except that
		//fp=fopen("chinesh.dat","rb+");    //we want to delete
	return 1;
}
void issuedbooks(){
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************************");
    gotoxy(2,2);
    printf(" BRANCH       ID    ROLLNUMBR     SECTION       SEM     STNAM     DUEDATE   BOOKNAME");
    j=4;
    fs=fopen("books.dat","rb");
    while(fread(&b,sizeof(b),1,fs)==1)
    {
	gotoxy(3,j);
	printf("%s",b.branch);
	gotoxy(16,j);
	printf("%d",b.id);
	gotoxy(22,j);
	printf("%d",b.rollnumber);
	gotoxy(36,j);
	printf("%s",b.section);
	gotoxy(50,j);
	printf("%d",b.sem);
	gotoxy(57,j);
	printf("%s",b.stname);
	gotoxy(66,j);
	printf("%s",b.duedate);
	gotoxy(85,j);
	printf("%s",b.name);
	printf("\n\n");
	j++;
	//i=i+a.quantity;
      }
      gotoxy(3,25);
      //printf("Total Books =%d",i);
      fclose(fs);
      gotoxy(35,25);
      returnfunc();
}
void issuebooks(){
    int d;
    system("cls");
    printf("1.Issue book \n");
    printf("2.View issued book \n");
    printf("3.Search issued book \n");
    printf("4.Remove issued book \n");
    printf("enter your choice \n");
    //scanf("%d",&d);
    switch(getch()){
    case '1':{
    fs=fopen("books.dat","ab+");
    if(getbooks()==1)
        {
    fseek(fs,0,SEEK_END);
	fwrite(&b,sizeof(b),1,fs);
	fclose(fs);
	gotoxy(21,14);
	printf("The book is sucessfully issued");
	gotoxy(21,15);
	printf("Save any more?(y / n):");
	if(getch()=='n')
	    mainmenu();
	else
	    system("cls");
	    issuebooks();
        }
    }
    case '2':{
        issuedbooks();
        break;
        }
    case '3':{

    int findbook;
    system("cls");
    gotoxy(10,4);
    printf("press 1 for search by ID \n");
    gotoxy(10,5);
    printf("press 2 for search by name \n");
    switch(getch()){
case '1':
     iid();
    break;
case '2':
    iname();
    break;
    }

}
case '4':{

    int d;
    printf("enter the book id to be submitted \n");
    scanf("%d",&d);
     fh=fopen("inter.dat","rb+");
	rewind(fh);

		while(fread(&a,sizeof(a),1,fh)==1)
		{
		    if(a.id==d) //getting problem here
		    {
		        fp=fopen("chinesh.dat","rb+");
		        fseek(fp,0,SEEK_END);
			fwrite(&a,sizeof(a),1,fp);
			fclose(fp);
		    }
		                                 //we want to delete
		}
		fclose(fh);

		fs=fopen("books.dat","rb+");
	rewind(fs);
	ft=fopen("delete.dat","wb+");  //temporary file for delete
		while(fread(&b,sizeof(b),1,fs)==1)
		{

		    if(b.id!=d)
		    {
            fseek(fd,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,fd); //write all in tempory file except that
		    }                              //we want to delete
		}
		fclose(fd);
		fclose(fs);
		remove("books.dat");
		rename("delete.dat","books.dat");

    fh=fopen("inter.dat","rb+");
	rewind(fh);
		while(fread(&a,sizeof(a),1,fh)==1)
		{

		    if(a.id!=d)
		    {
            fd=fopen("delete.dat","wb+");  //temporary file for delete
			fseek(fd,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,fd); //write all in tempory file except that
		    }                              //we want to delete
		}
		fclose(fd);
		fclose(fh);
		remove("inter.dat");
		rename("delete.dat","inter.dat");

		mainmenu();
}
    case '5':{ //to check for the record of the issed books(same as that in orignal libray and not displayed)
        int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;

    fh=fopen("inter.dat","rb");
     rewind(fh);
    while(fread(&a,sizeof(a),1,fh)==1)
    {
	gotoxy(3,j);
	printf("%s",a.cat);
	gotoxy(16,j);
	printf("%d",a.id);
	gotoxy(22,j);
	printf("%s",a.name);
	gotoxy(36,j);
	printf("%s",a.author);
	gotoxy(50,j);
	printf("%d",a.quantity);
	gotoxy(57,j);
	printf("%.2f",a.price);
	gotoxy(69,j);
	printf("%d",a.rackno);
	printf("\n\n");
	j++;
	i=i+a.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fh);
      gotoxy(35,25);
      returnfunc();
        }
    }
}
void iname(){
    int findbook;
    system("cls");
    char d[10];
    system("cls");
	gotoxy(10,5);
	printf("NOTE:DO NOT PUT BLANKS IN THE NAME");
	printf("Enter the Book name to  search: ");
	scanf("%s",&d);
	fs=fopen("books.dat","rb+");
	rewind(fs);
	while(fread(&b,sizeof(b),1,fs)==1)
	{
	    if(strcmp(d,b.name)==0)
	    {

		//gotoxy(10,7);
		printf("The book record is available");
		//gotoxy(10,8);
		printf("Book name is %s \n",b.name);
		//gotoxy(10,9);
		printf("Book name is %d \n",b.id);
		//gotoxy(10,10);
		printf("Author name is %s \n",b.duedate);
		//gotoxy(10,11);
		printf("no. of books are %d \n",b.rollnumber);
		//gotoxy(10,12);
		printf("Price is %s \n",b.branch);
		//gotoxy(10,13);
		printf("Rack No. is %s \n",b.stname);
		findbook='t';
		printf("\n \n \n \n");

		//fflush(stdin);
	    }

	}
	fclose(fp);
	if(findbook!='t')
	{
	    //gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    mainmenu();
	}
}
void iid(){ //for searching issued books by ID
    int d;
    int findbook;
    system("cls");
	gotoxy(10,5);
	printf("Enter the Book ID to  search:");
	scanf("%d",&d);
	fs=fopen("books.dat","rb+");
	rewind(fs);
	while(fread(&b,sizeof(b),1,fs)==1)
	{
	    if(b.id==d)
	    {
        system("cls");
		//gotoxy(10,7);
		printf("The book record is available");
		//gotoxy(10,8);
		//printf("Book name is %s \n",b.name);
		//gotoxy(10,9);
		printf("Book id is %d \n",b.id);
		//gotoxy(10,10);
		printf("Due date is %s \n",b.duedate);
		//gotoxy(10,11);
		printf("roll no. is %d \n",b.rollnumber);
		//gotoxy(10,12);
		printf("Branch is %s \n",b.branch);
		//gotoxy(10,13);
		printf("Student name is %s \n",b.stname);
		printf("\n \n \n \n");
		findbook='t';
		//fflush(stdin);
	    }
	    fclose(fs);
	}
	if(findbook!='t')
	{
	    gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    mainmenu();
	}
}
void returnfunc(void)
{
    {
	printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    mainmenu(); //ASCII value of enter key is 13
    else
    goto a;
}
void studentmenu(){
    system("cls");
       //	textbackground(13);
	int i;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	//show_mouse();
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. View Book list");
	gotoxy(20,6);
	printf("\xDB\xDB\xDB\xDB\xB2 2. issued books");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
	gotoxy(20,8);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Close Application");
	gotoxy(20,9);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,15);
    printf("Enter your choice:");
    switch(getch())
    {
		case '1':
		viewbooks();
		break;
	 case '2':
		issuedbooks();
		break;
    case '3':
		searchbooks();
	    break;
    case '4':
        thankyou();
		break;
    default:
		{
		gotoxy(10,23);
		printf("\aWrong Entry!!Please re-entered correct option");
		if(getch())
		mainmenu();
		}

    }
}
COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 void password_student(){
    system("cls");
    char student[10]={"student"};
    char pasword[10], ch;
 int i;
 gotoxy(25,2);
 printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ENTER PASSWORD\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
 gotoxy(25,3);

    gotoxy(25,4);
 for(i=0;i<7;i++)
 {
  ch = getch();
  pasword[i] = ch;
  ch = '*' ;
  printf("%c",ch);
 }
 printf("\n");

 pasword[i] = '\0';

if(strcmp(pasword,student)==0){
    studentmenu();
}
else{
    printf("password is incorrect");
    }
}

 void password(){
     /* system("cls");
    char password[10]={"password"};
    char pasword[10], ch;
 int i;
 gotoxy(25,2);
 printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ENTER PASSWORD\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
 gotoxy(25,3);
http://www.codeincodeblock.com/2012/04/list-of-top-ten-college-mini-projects.html

    gotoxy(25,4);
 for(i=0;i<8;i++)
 {
  ch = getch();
  pasword[i] = ch;
  ch = '*' ;
  printf("%c",ch);
 }
 printf("\n");

 pasword[i] = '\0';

if(strcmp(pasword,password)==0){
    mainmenu();
}
else{
    printf("password is incorrect");
    } */
    mainmenu();
}
int main()
{
    gotoxy(25,2);
    printf("press 1 for staff \n");
    gotoxy(25,3);
    printf("press 2 for student \n");
    gotoxy(25,4);
    switch(getch())
	{
		case '1':
        password();
		break;


	case '2':
	    password_student();
	    break;
	}
    return 0;


}


