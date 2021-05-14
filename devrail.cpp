#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void userreg();
void userlogin();
void home();
void menu();
void booking();
void viewtic();
void ticketno();
void profile();
void viewtrain();
void edit();
void cancell();


struct booking{
	char name[20];
	char dob[20];
	char doj[20];
	char so[20];
	char gen[5];
	char mob[20];
	char add[30];
	char trainno[7];
	int ticketno;
	
};

struct data
{
    char username[10];
    char password[10];
    char dob[20];
    char so[20];
    char mo[20];
	char gen[5];
	char mob[20];
	char id[25];
	char add[30];
};


void home(){
int i,choice;
    printf("\n\t\t\t/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*");
    printf("\n\t\t\t/*\t\t\t\t\t\t*/");
    printf("\n\t\t\t/*\t   WELCOME TO THE NORTH RAILWAY\t\t*/");
    printf("\n\t\t\t/*\t\t\t\t\t\t*/");
    printf("\n\t\t\t*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/");
    printf("\n\n\n\n\t\t\t\t   Press Enter to proceed...!!");
    if(getch()==13)
    XY:
     for(i=0;i<100;i++)
    {
  system("color 02");
  printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER\t\t3. EXIT ");
  printf("\n\n\n\t\t\t\t\tENTER YOUR CHOICE: ");
  scanf("%d",&choice);
    system("cls");
    switch(choice){
    case 1:
            userlogin();
            break;
    case 2:
            userreg();
            break;
    case 3: exit(0);
    default:
         printf("\nplease choose write option !!");
    }
    }
}

void menu(){
	int y;
	system("cls");
	system("color 03");
	printf("\n\t\t\t/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*");
    printf("\n\t\t\t/*\t\t\t\t\t\t*/");
    printf("\n\t\t\t/*\t   WELCOME TO THE NORTH RAILWAY\t\t*/");
    printf("\n\t\t\t/*\t\t\t\t\t\t*/");
    printf("\n\t\t\t*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/");
    printf("\n\n\t-------------------------------------------------------------------------------------");
	printf("\n\t|   SELECT ONE OPTION :-                                                            |");
	printf("\n\t|                                                                                   |");
	printf("\n\t|      1.VIEW TRAINS           2.BOOK TICKET             3.VIEW TICKETS             |");
	printf("\n\t|                                                                                   |");
    printf("\n\t|      4.SEARCH TICKET NO.     5.CENCEL TICKET           6.VIEW PROFILE             |");
	printf("\n\t|                                                                                   |");
	printf("\n\t|      7.VIEW TICKET BY TICKET NO.                       8.QUIT                     |");
	printf("\n\t|                                                                                   |");
	printf("\n\t-------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t  ENTER A CHOICE:   ");
	scanf("%d",&y);
	system("cls");
	switch(y){
	case 1:
	     viewtrain();
		 break;
	case 2:
	    booking();
		break;
	case 3:
	     viewtic();	
	case 4:
	     ticketno();
	case 5:
	     cancell();     
	case 6:
	     profile();	 	 	 
	case 7:
	     exit(0);
	default:
	     printf("\n\t\t\t\tWRONG CHOICE PLEASE CHOOSE ANOTHER OPTION!!");	 	 	
	}
}

void booking(){
	int x,r,count;
    struct booking b;
    srand(time(NULL));
    count=rand()%100+1;
   	b.ticketno=count;
	FILE *fp;
    fp=fopen("booking.txt","a+");
    system("color 04");
    printf("\n\n\t\t\t\t\tWELCOME TO TICKET BOOKING  ZONE");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\tenter the name of the passenger:\t");
    scanf("%s",&b.name);
    printf("\n\t\t\t\tenter the father name:\t\t\t");
    scanf("%s",&b.so);
    printf("\n\t\t\t\tdate of journey:      \t\t\t");
    scanf("%s",&b.doj);
    printf("\n\t\t\t\tdate of birth:\t\t\t\t");
    scanf("%s",&b.dob);
    printf("\n\t\t\t\tgender:  \t\t\t\t");
    scanf("%s",&b.gen);
    printf("\n\t\t\t\tenter the mobile no: \t\t\t");
    scanf("%s",&b.mob);
    printf("\n\t\t\t\tenter your address \t\t\t");
    scanf("%s",&b.add);
    printf("\n\t\t\t\tenter train no in which you want to travell: ");
    scanf("%s",&b.trainno);
    fprintf(fp,"%s %s %s %s %s %s %s %s %d",b.name,b.so,b.doj,b.dob,b.gen,b.mob,b.add,b.trainno,b.ticketno);
    fclose(fp);
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\n\t\t\t\tpress 1 for book ticket another for go to main menu:   ");
    scanf("%d",&r);
    if(r==1){
    	printf("\n\n\t\t--------------------------------------------------------------------");
    	printf("\n\t\t\t\tYOUR TICKET HAS BEEN SUCCESSFULLY BOOKED!!!!");
    	printf("\n\n\t\t--------------------------------------------------------------------");
    	printf("\n\t\t\t\tPRESS 1 FOR GOTO MAIN MENU ANOTHER FOR EXIT !");
    	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		home();
		}
		else
		exit(0);
	}
	else
	exit(0);
        
        		
}

void viewtic(){
	FILE *fp;
	struct booking b;
	int x,y,c=0;
	char mobile[20],birth[20];
	fp=fopen("booking.txt","r");
	printf("\n\n\n\t\t\t\t ENTER MOBILE NUMBER:  ");
	scanf("%s",&mobile);
	printf("\n\n\n\t\t\t\t ENTER DATE OF BIRTH:  ");
	scanf("%s",&birth);
		while(fscanf(fp,"%s %s %s %s %s %s %s %s %d",b.name,b.so,b.doj,b.dob,b.gen,b.mob,b.add,b.trainno,&b.ticketno) != EOF){
		x=strcmp(b.mob,mobile);
		if(x==0){
		y=strcmp(b.dob,birth);
		if(y==0){	
		system("color 30");
		system("cls");
    printf("\n\n\t\t\t\t\tNORTH RAILWAY TICKET ");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\tname of the passenger:\t\t %s",b.name);
    printf("\n\t\t\t\tfather name:\t\t\t %s",b.so);
    printf("\n\t\t\t\tdate of journey:      \t\t %s",b.doj);
    printf("\n\t\t\t\tdate of birth:\t\t\t %s",b.dob);
    printf("\n\t\t\t\tgender:  \t\t\t %s",b.gen);
    printf("\n\t\t\t\tmobile no: \t\t\t %s",b.mob);
    printf("\n\t\t\t\taddress \t\t\t %s",b.add);
    printf("\n\t\t\t\ttrain no in which you travell:   %s",b.trainno);
    printf("\n\t\t\t\tyour ticket no is:   \t\t %d",b.ticketno);
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\t\t\t\tPRESS 1 FOR GOTO MAIN MENU ANOTHER FOR EXIT !:  \t");
   	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		home();
		}
		else{
		exit(0);
	}

		c=1;
			}
		}
	}	
if(c==0)
	{   system("color 04");
		printf("\n\n\t\t--------------------------------------------------------------------");
		printf("\n\t\t\t\twrong dob/mobile numbers!!!");
		printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\t\t\t\tPRESS 1 FOR GOTO MAIN MENU ANOTHER FOR EXIT !:  \t");
   	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		home();
		}
		else{
		exit(0);
	}
	}

	fclose(fp);
	getch();
}

void ticketno(){
	FILE *fp;
	struct booking b;
	int x,y,c=0;
	char mobile[20],birth[20];
	fp=fopen("booking.txt","r");
	printf("\n\n\n\t\t\t\t ENTER MOBILE NUMBER:  ");
	scanf("%s",&mobile);
	printf("\n\n\n\t\t\t\t ENTER DATE OF BIRTH:  ");
	scanf("%s",&birth);
		while(fscanf(fp,"%s %s %s %s %s %s %s %s %d",b.name,b.so,b.doj,b.dob,b.gen,b.mob,b.add,b.trainno,&b.ticketno) != EOF){
		x=strcmp(b.mob,mobile);
		if(x==0){
		y=strcmp(b.dob,birth);
		if(y==0){	
		system("color 30");
		system("cls");
    printf("\n\n\t\t\t\t\tTHANKYOU FOR TRAVELL WITH US ");
    printf("\n\t\t\t\t#####^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#####");
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\t\t\t\tyour ticket no is:   \t\t %d",b.ticketno);
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\t\t\t\tPRESS 1 FOR GOTO MAIN MENU ANOTHER FOR EXIT !:  \t");
   	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		home();
		}
		else{
		exit(0);
	}

		c=1;
			}
		}
	}	
if(c==0)
	{   system("color 04");
		printf("\n\n\t\t--------------------------------------------------------------------");
		printf("\n\t\t\t\twrong dob/mobile numbers!!!");
		printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\t\t\t\tPRESS 1 FOR GOTO MAIN MENU ANOTHER FOR EXIT !:  \t");
   	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		home();
		}
		else{
		exit(0);
	}
	}

	fclose(fp);
	getch();
}

	  
void viewtrain(){
	FILE *fp;
	int a;
	char train[3000];
	fp=fopen("trains.txt","r");
	fread(&train,sizeof(train),1,fp);
	printf("%s",train);
  fclose(fp);
  printf("\n\t\t--------------------------------------------------------------------");
        printf("\n\n\t\t\t\tpress 0 for goto home another for exit:   ");
        scanf("%d",&a);
        if(a==0){
		
          system("cls");
           home();
       }
        else
            exit(0);

  getch();
}

void profile(){
     FILE *fp;
     int id,x,count=0;
     char mobile[20];
    struct data d;
    fp=fopen("user.txt","r");
    system("color 40");
    printf("\n\n\t\t\t\tWELCOME TO VERIFICATION ZONE");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\n\t\t-------------------------------------------------------------------");
    printf("\n\n\t\t\t\tENTER MOBILE NO. : ");
    scanf("%s",mobile);
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",d.username,d.password,d.so,d.mo,d.dob,d.gen,d.mob,d.id,d.add)!=EOF){
    id=strcmp(mobile,d.mob);	
    if(id==0){
    system("cls");
    printf("\n\n\t\t\t\t\tYOUR PROFILE ");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\n\t\t-------------------------------------------------------------------");
	printf("\n\n\n\t\t\t\tUSERID:   \t\t%s",d.username);
	printf("\n\t\t\t\tPASSWORD: \t\t%s",d.password);
	printf("\n\t\t\t\tFATHER'S NAME:    \t%s",d.so);
	printf("\n\t\t\t\tMOTHER'S NAME:    \t%s",d.mo);
	printf("\n\t\t\t\tDATE OF BIRTH:    \t%s",d.dob);
	printf("\n\t\t\t\tGENDER:    \t\t%s",d.gen);
	printf("\n\t\t\t\tMOBILE NO:  \t\t%s",d.mob);
    printf("\n\t\t\t\tEMAIL-ID:    \t\t%s",d.id);
	printf("\n\t\t\t\tADDRESS:     \t\t%s",d.add);
	count=1;
	printf("\n\n\t\t-------------------------------------------------------------------");
	printf("\n\t\t\t\tPRESS 1 FOR GOTO MAIN MENU 2 FOR EDIT PROFILE !:\t");
   	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		home();
		}
		else{
		edit();
    	}
    }
  }
if(count==0){
	system("color 04");
   	printf("\n\n\n\t\t\t\tWRONG MOBILE NO PLEASE ENTER VALID MOBILE NO.!!");
	printf("\n\n\n\t\t\t\tPRESS 1 FOR GOTO MAIN MENU ANOTHER FOR EXIT !:  \t");
   	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		home();
		}
		else{
		exit(0);
	 }	
  }
  fclose(fp);
}

void edit()
{
	FILE *fp1,*fp2;
    int i,z,ch,id,a,p;
    char users[10],pass[10];
    char daofb[10],mobi[20],email[20],addr[30],passw[10];
    struct data d;
    fp1=fopen("user.txt","r");
    fp2=fopen("temp.txt","w");
    system("cls");
    system("color 40");
    printf("\n\n\t\t\t\t\tWELCOME TO VERIFICATION ZONE");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\n\t\t-------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\tenter the username:  ");;
	scanf("%s",&users);
    printf("\n\t\t\t\tenter the password:  ");
    z=0;
       while(1){
	   ch=getch();
        if(ch==13){
            break;
        }
        else{
            pass[z]=ch;
            putch('*');
            z++;
        }
    }
    while(fscanf(fp1,"%s %s %s %s %s %s %s %s %s ",d.username,d.password,d.so,d.mo,d.dob,d.gen,d.mob,d.id,d.add)!=EOF){   	
    id=strcmp(d.username,users);
    if(id!=0){
     p=strcmp(d.password,pass);
	 if(p!=0){
	fprintf(fp2,"%s %s %s %s %s %s %s %s %s ",d.username,d.password,d.so,d.mo,d.dob,d.gen,d.mob,d.id,d.add);
    }
 }
   else{
   	printf("\n\n\t\t--------------------------------------------------------------------");   
    printf("\n\n\t\t\t\tWELCOME TO EDIT PROFILE ZONE");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\n\t\t-------------------------------------------------------------------");
    printf("\n\t\t\t\tdate of birth:\t\t\t\t");
    scanf("%s",&daofb);
    printf("\n\t\t\t\tenter new mobile no: \t\t\t");
    scanf("%s",&mobi);
    printf("\n\t\t\t\tenter new email-id : \t\t\t");
    scanf("%s",&email);    
    printf("\n\t\t\t\tenter new address \t\t\t");
    scanf("%s",&addr);
    printf("\n\t\t\t\tenter new password:\t\t\t");
    z=0;
    while(1){
        ch=getch();
        if(ch==13){
            break;
        }
        else{
            passw[z]=ch;
            putch('*');
            z++;
        }
    }
    fprintf(fp2,"%s %s %s %s %s %s %s %s %s ",d.username,d.password,d.so,d.mo,daofb,d.gen,mobi,email,addr);   	
   } 
}
   fclose(fp1);
   fclose(fp2);
   remove("user.txt");
   rename("temp.txt","user.txt");  
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\n\t\t\t\tpress 0 for goto home another for exit:   ");
        scanf("%d",&a);
        if(a==0){
          system("cls");
           home();
       }
        else
            exit(0);

}
void cancell()
{
  	FILE *fp1,*fp2;
    int m,a,s=0;
    char mobile[20];
    struct booking b;
    fp1=fopen("booking.txt","r");
    fp2=fopen("temperary.txt","w");
    system("cls");
    system("color 40");
    printf("\n\n\t\t\t\t\tWELCOME TO CANCELLATION ZONE");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\n\t\t-------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\tenter the mobile no:  ");
	scanf("%s",&mobile);	
    while(fscanf(fp1,"%s %s %s %s %s %s %s %s %d",b.name,b.so,b.doj,b.dob,b.gen,b.mob,b.add,b.trainno,&b.ticketno)!=EOF){   	
    m=strcmp(b.mob,mobile);
    if(m!=0){
    	fprintf(fp2,"%s %s %s %s %s %s %s %s %d",b.name,b.so,b.doj,b.dob,b.gen,b.mob,b.add,b.trainno,b.ticketno);
    }
    else{
    	s=1;
	}
	 
}
 if(s==1){
   	printf("TICKET IS CANCELL SUCCESSFULLY!!");
   }
   if(s==0){
   	printf("TICKET DOES NOT EXIST BY THIS MOBILE NO!!!");
   }
   fclose(fp1);
   fclose(fp2);
   remove("booking.txt");
   rename("temperary.txt","booking.txt");  
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\n\t\t\t\tpress 0 for goto home another for exit:   ");
        scanf("%d",&a);
        if(a==0){
		
          system("cls");
           home();
       }
        else
            exit(0);

}

void userlogin()
{
    char user[10],pass[10];
    int res,id,f=0,ch,z;
    FILE *fp;
    struct data d;
    fp=fopen("user.txt","r");
    printf("\n\n\t\t\t\t\tWELCOME TO LOG IN ZONE");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\n\t\t-------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\tenter the username:  ");;
	scanf("%s",&user);
    printf("\n\t\t\t\tenter the password:  ");
    z=0;
       while(1){
	   ch=getch();
        if(ch==13){
            break;
        }
        else{
            pass[z]=ch;
            putch('*');
            z++;
        }
    }
   printf("\n\n\t\t--------------------------------------------------------------------");
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",d.username,d.password,d.so,d.mo,d.dob,d.gen,d.mob,d.id,d.add)!=EOF){
    res = strcmp(user,d.username);
    if(res==0){
        id=strcmp(pass,d.password);
        if(id==0){
        printf("\n\n\t\t\t YOU ARE SUCCESSFULLY LOGGED IN PRESS ENTER FOR PROCCED");
        printf("\n\n\t\t--------------------------------------------------------------------");
        if(getch()==13)
        menu();
        f=1;
        }
    }
  }
  if(f==0){
  	system("color 04");
    printf("\n\n\t\t\t\twrong passeord and username!!!");
    printf("\n\n\t\t--------------------------------------------------------------------");
   }
  fclose(fp);
  getch();
}

void userreg(){
    int i,z,ch,id,a;
    char username[10];
    struct data d;
    FILE *fp;
    fp=fopen("user.txt","a+");
        printf("\n\n\t\t\t\t\tWELCOME TO REGISTER IN ZONE");
    printf("\n\t\t\t\t###^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^###");
    printf("\n\n\t\t--------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\tenter the unique username:  \t\t");
    scanf("%s",&username);
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",d.username,d.password,d.so,d.mo,d.dob,d.gen,d.mob,d.id,d.add)!=EOF){
        id=strcmp(username,d.username);
        if(id==0){
        system("color 04");
        printf("\n\n\t\t--------------------------------------------------------------------");
        printf("\n\n\t\t\t\tplease enter the unique username");
        printf("\n\n\t\t--------------------------------------------------------------------");
        printf("\n\n\t\t\t\tpress 0 for goto home another for exit:   ");
        scanf("%d",&a);
        if(a==0){
		
          system("cls");
           home();
       }
        else
            exit(0);

    }
}
    printf("\n\t\t\t\tenter the password:\t\t\t");
    z=0;
    while(1){
        ch=getch();
        if(ch==13){
            break;
        }
        else{
            d.password[z]=ch;
            putch('*');
            z++;
        }
    }
    printf("\n\n\t\t\t\tenter the father name:\t\t\t");
    scanf("%s",&d.so);
    printf("\n\t\t\t\tenter the mother's name:      \t\t");
    scanf("%s",&d.mo);
    printf("\n\t\t\t\tdate of birth:\t\t\t\t");
    scanf("%s",&d.dob);
    printf("\n\t\t\t\tgender:  \t\t\t\t");
    scanf("%s",&d.gen);
    printf("\n\t\t\t\tenter the mobile no: \t\t\t");
    scanf("%s",&d.mob);
    printf("\n\t\t\t\tenter the email-id : \t\t\t");
    scanf("%s",&d.id);    
    printf("\n\t\t\t\tenter your address \t\t\t");
    scanf("%s",&d.add);
    printf("\n\n\t\t--------------------------------------------------------------------");
    fprintf(fp,"%s %s %s %s %s %s %s %s %s ",username,d.password,d.so,d.mo,d.dob,d.gen,d.mob,d.id,d.add);
    printf("\n\n\t\t\t\tyou have successfully registered ");
    fclose(fp);
    printf("\n\n\t\t--------------------------------------------------------------------");
        printf("\n\n\t\t\t\tpress 0 for goto home another for exit:   ");
        scanf("%d",&a);
        if(a==0){
		
          system("cls");
           home();
       }
        else
            exit(0);

}


int main()
{
    home();
    return 0;
}

