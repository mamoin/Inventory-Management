#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

struct invent_record
{
    char name[100];
    int quantity;
    int price;
    unsigned date;
} item;

struct memo
{
    char itemname[100];
    int quantity;
    int  price;
} sell;
int ii1;
int ii2;

void init_list(void);
void add(void);
void edit(void);
void list(void);
int menu_select(void);
void bill(void);
void search(void);


int top=0;

void main()
{
    char choice;
    /*  **************Opening page************* */

    printf("\n\n\n\n\n\n\n\n\n\n\n");

    printf("             WELCOME TO SHOP MANAGEMENT  \n\n\n\n\n\n\n\n\n\n\n");
    printf("                         Done By:       \n");
    printf("               Mohammad Abdul Moin Oninda\n");
    printf("                     I.D - 132428 \n\n\n\n");

    /* **************************SIGN UP/RECIEVE PASSWORD/CHECK PASSWORD**************************** */
    FILE *f1,*f2;
    int a;
    int b=0;
    int d;
    int i;
    int upper;
    int lower;
    int digit;
    int special;
    int L1;
    int n=0;
    int j;

    char A[100];
    char B[100];
    char c;
    char E;
    char e;
    char Z[100];
    char Y[100];
    char H[100];
    char F[100];
    char G[100];
    printf("Press 1 for Sign Up\nPress 2 for Sign In\n");
    printf("Enter Your Choice\n");
    scanf("%d",&a);
    if(a==1)
    {
        printf("Enter Your Username\n");
        scanf("%s",A);
        printf("\n");
        printf("Password Must be Between 6-16 Characters\nThere Should be at least:\nOne Upper Case Letter\nOne Lower Case Letter\n One Digit\nOne Special Character\n ");
        while(1)
        {
            while(1)
            {
                c=getch();
                if(c!='\r')
                {
                    B[b]=c;
                    if(B[b]!='\0')
                        printf("*");
                }
                else
                {
                    B[b]='\0';
                    break;
                }
                b++;
            }

            L1=strlen(B);
            printf("\n");
            d=0;
            upper=0;
            lower=0;
            digit=0;
            special=0;
            while(B[d]!='\0')
            {
                if(B[d]>='A'&&B[d]<='Z')
                {
                    upper++;
                }
                else if(B[d]>='a'&&B[d]<='z')
                {
                    lower++;
                }
                else if(B[d]>='0'&&B[d]<='9')
                {
                    digit++;
                }
                else
                {
                    special++;
                }

                d++;
            }
            if(upper>=1&&lower>=1&&digit>=1&&special>=1&&L1>=6&&L1<=16)
            {
                printf("Password Valid\n\n");

                break;
            }
            else
            {
                printf("Password Invalid\nRetype Password\n");
                b=0;
            }

        }
        f1=fopen("User.txt","a");
        f2=fopen("Password.txt","a");
        fprintf(f1,"%s\n",A);
        fprintf(f2,"%s\n",B);
        fclose(f1);
        fclose(f2);
        printf("Sign Up Successful");
        printf("Do You Want To Log In Y/N\n");
        e=getch();
        if(e=='Y'||e=='y')
        {
            printf("Welcome to Log in Page");
        }
    }
    else if(a==2)
    {
        f1=fopen("User.txt","r");
        while(1)
        {
            E=fgetc(f1);
            if(E=='\n')
                n++;
            else if(E==EOF)
                break;
        }
        fclose(f1);
        while(1)
        {
            printf("Enter Your User Name\n");
            scanf("%s",Z);
            f1=fopen("User.txt","r");
            for(i=0; i<n; i++)
            {
                H[0]='\0';
                fscanf(f1,"%s",H);
                if(strcmp(Z,H)==0)
                    break;
            }
            fclose(f1);
            if(strcmp(Z,H)==0)
                break;

            else
                printf("Invalid User name\n");
        }
        while(1)
        {
            printf("Enter Your Password\n");
            f2=fopen("Password.txt","r");
            b=0;
            while(1)
            {
                c=getch();
                if(c!='\r')
                {
                    G[b]=c;
                    if(G[b]!='\b')
                        printf("*");
                }
                else
                {
                    G[b]='\0';
                    break;
                }
                b++;
            }
            printf("\n");
            for(j=0; j<=i; j++)
            {
                fscanf(f2,"%s",F);
            }
            fclose(f2);
            if(strcmp(G,F)==0)
                break;
            else
                printf("Invalid Password\n");
        }
        printf("Sign In Successful");
        getch();
    }
    printf("Welcome to the Admin Panel\n\n\n");     /* Admin panel */
    printf("Main Menu\n\n");

    init_list;
    do
    {
        choice=menu_select();
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            list();
            break;
        case 4:
            search();
            break;
        case 5:
            bill();
            break;
        }
    }
    while(choice!=6);
    return 0;
}

void init_list(void)        /* Initialization*/
{
    register int t;
    for(t=0; t<100; ++t)
    {
        item.name[0]='\0';
    }
}


int menu_select(void)         /*Main menu*/
{
    char str[100];
    int c;
    printf("1.Add an Item\n");
    printf("2.Edit File\n");
    printf("3.Display All Goods\n");
    printf("4.Search For Goods\n");
    printf("5.Calculate Bill\n");
    printf("6.End\n");
    do
    {
        printf("\nEnter Your Choice :  ");
        gets(str);
        c=atoi(str);
        printf("\n");
    }
    while(c<0||c>7);
    return c;
}

void add(void)
{
    FILE *fp;
    int number,quantity,i;
    float price;
    char name[100];
    char record[100];

    printf("Input file name\n");
    scanf("%s", record);
    fp=fopen("record.txt","w");
    printf("Input Inventory Data\n\n");
    printf("Item Name     Quantity     Price\n");
    for(i=1; i<=4; i++)
    {

        fscanf(stdin,"%s%s%s",item.name,&item.quantity,&item.price);
        fprintf(fp,"%s     %s     %s\n",item.name,&item.quantity,&item.price);
    }
    fclose(fp);
    return 0;
}

void edit(void)       /*Append or Update(Replacement)*/
{
    struct invent_record;
    FILE *fid;
    char a[60];
    printf("Enter the name of the file\n");
    scanf("%s",a);
    fid=fopen(a,"a+");
    printf("Enter what you want to append to the file %s :\n",a);
    scanf("%s",item.name);
    scanf("%d",&ii1);
    scanf("%d",&ii2);
    fprintf(fid,"%s %d %d",item.name,ii1,ii2);
    printf("Append Successfully to the file");
    fclose(fid);
    return 0;
}

void search(void)      /* Searching for a particular item */
{
    struct invent_record;
    FILE *fid1;
    char b[100];
    char str[20];
    int N;
    printf("Enter Your Product Name: ");
    gets(b);
    fid1=fopen("record.txt","r");
    while(1){

        fscanf(fid1, "%s",str);
        if(strcmp(b,str)==0){
            printf("\n\t----------------------------------------------------------------------------------\n");
            fprintf(stdout, "\t\t%s ", str);
            fscanf(fid1,"%s",str);
            fprintf(stdout, "\t\t%s", str);
            fscanf(fid1,"%s",str);
            fprintf(stdout, "\t\t%s ", str);
            printf("\n\t----------------------------------------------------------------------------------\n");
        }
    }
    fclose(fid1);

}

void list(void)     /* Display all item */
{
  FILE *fid1;
    char str[20];
    int cnt=0;
    fid1=fopen("record.txt","r");
    printf("\n\t----------------------------------------------------------------------------------\n");
    while(fscanf(fid1, "%s",str)!=EOF){

        fprintf(stdout, "\t\t%s", str);
        cnt++;
        if(cnt==3){
            printf("\n\t----------------------------------------------------------------------------------");
            printf("\n");
        }
    }
    printf("\n\t----------------------------------------------------------------------------------\n");
    printf("\n");
    fclose(fid1);
}

void bill(void){
    char str[100];
    int qunt;
    float price;
    printf("Enter Name: ");
    scanf("%s", str);
    printf("Enter Quantity: ");
    scanf("%d", &qunt);
    printf("Enter Price: ");
    scanf("%f",&price);
    printf("Total Bill: %f", price*(float)qunt);
    printf("\nthank you for shopping\n");
}































