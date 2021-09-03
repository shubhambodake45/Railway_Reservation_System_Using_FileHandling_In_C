#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_adm
{
    char adname[50], adpassword[50];
    struct node_adm *next;
};

struct node_user
{
    char name[30], gender[2], email[50], clas[10];
    char tna[100], src[50], dest[50];
    int nop, age, cage, n, adult, child, not, ptno;
    char mobno[20];
    char idno[30];
    char x[10];
    int ttt, tno;
    char source[20], destination[20], date[20], data[100], alltrains[500];
    float fare, cfare, insurance, total, km, arr, dept;
    struct node_user *next;
};

struct node_train
{
    int tno;
    float km, arr, dept, ttt;
    char src[50], dest[50], tna[50];
    struct node_train *next;
};

struct pop
{
    int tno;
    char tna[100], src[50], dest[50];
    float km, arr, dept, ttt;
};

void adminprofile();
void loggedadmin();
void admin();
void readadmin();
void writeadmin();
void deleteadmin();
void displayadmin();

void railwaydatabase();
void readdatabase();
void writedatabase();
void displaytrains();
void inserttrains();
void inserttrainsbw();
void sorttrains();
void writesorteddb();
void readsorteddb();
void displaysortedtrains();
void deletetrains();
void searchtrains();
void specialtraindisplay();

void trainenquiry();

void book();
void read();
void write();
void display1();
void trainselect();
void payout();
void payoutwrite();
void display();
void displaysearchtrainticket();

struct node_adm *head_adm = NULL, *last_adm = NULL, *a;
struct node_user *head_user = NULL, *last_user = NULL, *u = NULL;
struct node_train *head_train = NULL, *last_train = NULL, *t = NULL;
struct pop obj;

int ch, n, found = 0, i = 0;
int status1;
char str1[30], str2[30], adname[50], adpassword[50], ch1[] = "y", ch2[5];
char input[255];
float pkm, fare, afare, tfare;
char filepath1[200] = "D:\\Shubham\\Study Material\\2nd Year\\2nd SEM\\DS\\Lab\\Course Project\\Project\\Passenger Details\\" ;
char filepath2[200] = "D:\\Shubham\\Study Material\\2nd Year\\2nd SEM\\DS\\Lab\\Course Project\\Project\\Booking Receipt\\" ;

int main()
{
    FILE *infile;

    //system("color f1");
    do
    {
        system("CLS");
        printf("\n----------------------------------------------------------------------------\n");
        printf("                     Welcome to Railway Reservation System");
        printf("\n----------------------------------------------------------------------------\n");
        printf(" \n\t\t 1. ADMIN \n\n\t\t 2. USER \n\n\t\t 0. EXIT");
        printf("\n----------------------------------------------------------------------------\n");
        printf("                                                            ");
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tChoice:\t");
        scanf("\t%d", &ch);

        switch (ch)
        {
        case 0:
            exit(0);
            break;

        case 1:
            system("cls");
            printf("\n----------------------------------------------------------------------------\n");
            printf("                     Welcome ADMIN");
            printf("\n----------------------------------------------------------------------------\n");

            readadmin();
            a = head_adm;

            printf("\n Enter Name    : ");
            scanf("%s", str1);
            printf(" Enter Password  : ");
            i = 0;
            while (i <= 9)
            {
                str2[i] = getch();

                if (str2[i] == 13)
                    break;
                else
                    printf("*");

                i++;
            }
            str2[i] = '\0';

            for (int i = 1; a != NULL; i++)
            {
                if ((strcmp(a->adname, str1) == 0) && (strcmp(a->adpassword, str2) == 0))
                {
                    strcpy(adname, a->adname);
                    strcpy(adpassword, a->adpassword);
                    found = 1;
                }
                a = a->next;
            }

            if (found == 1)
            {
                do
                {
                    system("CLS");
                    printf("\n---------------------------------------------\n");
                    printf("                   Admin Menu                      ");
                    printf("\n---------------------------------------------\n");
                    printf("\n\t1. Railway Database\n\t");
                    printf("2. Train Enquiry\n\t3. Profile Settings\n\t0. EXIT \n\n\t");
                    printf("Choice:\t");
                    scanf("%d", &ch);

                    switch (ch)
                    {
                    case 0:
                        exit(0);
                        break;

                    case 1:
                        system("CLS");
                        railwaydatabase();
                        break;

                    case 2:
                        system("CLS");
                        trainenquiry();
                        break;

                    case 3:
                        system("CLS");
                        adminprofile();
                    }
                    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\tWant to Continue[Admin Menu] (y/n):\t");
                    scanf("%s", &ch2);
                    strlwr(ch2);
                } while ((strcmp(ch2, ch1)) == 0);
            }
            else
            {
                system("CLS");
                printf("\n\n\n\t!! INVALID CREDENTIALS ...... Enter Correct Username And Password !!\n\n");
            }
            break;

        case 2:
            do
            {
                system("CLS");
                printf("\n---------------------------------------------\n");
                printf("                 USER Menu                      ");
                printf("\n---------------------------------------------\n");
                printf("\n\t1. Book ticket\n\t");
                printf("2. Display Booked ticket");
                printf("\n\t3. Train Enquiry\n\t4. Cancel ticket\n\t0. EXIT \n\n\t");
                printf("Choice:\t");
                scanf("%d", &ch);

                switch (ch)
                {
                    case 0:
                        exit(0);
                        break;

                    case 1:
                        system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                     Ticket Booking");
                        printf("\n----------------------------------------------------------------------------\n");
                        book();
                        trainselect();
                        payout();
                        break;

                    case 2:
                        system("CLS");
                        system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                             Booked ticket");
                        printf("\n----------------------------------------------------------------------------\n");
                        display();
                    
                        infile = fopen("Booking_reciept.txt", "r");
                        u = head_user;
                        
                        printf("\n\nFARE DETAILS : ");
                        printf("\n\t Train_no                : %d\n\t Source                  : %s\n\t Destination             : %s\n\t Date                    : %s\n\t Total_fare(Without_Ins) : %.2f\n\t Total_fare(With_Ins)    : %.2f\n ", u->ptno , u->source , u->destination , u->date , fare, tfare);
                        fclose(infile);

                         displaysearchtrainticket();
                        break;

                    case 3:
                        system("CLS");
                        trainenquiry();
                        break;

                    case 4:{
                        system("CLS");
                        infile = fopen(filepath2 , "w");
                        fprintf(infile , "Ticket has been cancelled");
                        printf("Your ticket has been cancelled\nAmount will be refunded in 2-3 working days!");
                        fclose(infile);
                        break;
                    }
                }
                printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n\tWant to Continue[USER Menu] (y/n):\t");
                scanf("%s", &ch2);
                strlwr(ch2);
            } while ((strcmp(ch1, ch2)) == 0);
            break;
        }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Login Page] (y/n):\t");
        scanf(" %s", &ch2);
        strlwr(ch2);
    } while ((strcmp(ch2, ch1)) == 0);
}


void adminprofile()
{
    do
    {

        system("CLS");
        printf("\n---------------------------------------------\n");
        printf("              PROFILE SETTINGS                   ");
        printf("\n---------------------------------------------\n");
        printf("\n\t1. Add Admins\n\t");
        printf("2. Display Admins");
        printf("\n\t3. Delete Admin\n\t0. EXIT \n\n\t");
        printf("Choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            system("CLS");
            loggedadmin();
            admin();
            break;
        case 2:
            system("CLS");
            loggedadmin();
            displayadmin();
            break;
        case 3:
            system("CLS");
            loggedadmin();
            deleteadmin();
            break;
        case 0:
            system("CLS");
            exit(0);
            break;
        }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\t Want to Continue[Profile Setting] (y/n):\t");
        scanf(" %s", &ch2);
        strlwr(ch2);
    } while ((strcmp(ch1, ch2)) == 0);
}

void loggedadmin()
{
    printf("\n\n\n---------------------------------------------\n");
    printf("            Logged In Admin:\t");
    printf("%s", adname);
    printf("\n---------------------------------------------\n");
}

void admin()
{
    int i = 0;
    readadmin();
    char str1[20], str2[20], str3[20], str4[20];
    printf("\n Enter New Admin Name         :\t");
    scanf("%s", str1);
    printf(" Enter New Admin Password     :\t");

    while (i <= 9)
    {
        str2[i] = getch();
        if (str2[i] == 13)
            break;
        else
            printf("*");
        i++;
    }
    str2[i] = '\0';

    printf("\n Confirm Password             :\t");
    i = 0;
    while (i <= 9)
    {
        str3[i] = getch();
        if (str3[i] == 13)
            break;
        else
            printf("*");
        i++;
    }
    str3[i] = '\0';

    printf("\n Enter logged admin password  :\t");
    i = 0;

    while (i <= 9)
    {
        str4[i] = getch();
        if (str4[i] == 13)
            break;
        else
            printf("*");
        i++;
    }
    str4[i] = '\0';

    if ((strcmp(str2, str3) == 0) && ((strcmp(str4, adpassword) == 0)))
    {
        a = last_adm;

        if (last_adm == NULL)
        {
            i = 1;
            last_adm = (struct node_adm *)malloc(sizeof(struct node_adm));
            last_adm->next = NULL;
            strcpy(last_adm->adname, str1);
            strcpy(last_adm->adpassword, str2);
            a = last_adm;
            head_adm = last_adm;
        }
        else
        {

            a = last_adm;
            a->next = (struct node_adm *)malloc(sizeof(struct node_adm));
            a = a->next;
            last_train = a;
            strcpy(a->adname, str1);
            strcpy(a->adpassword, str2);
            a->next = NULL;
        }
        writeadmin();
        printf("\n\n\t!! Admin Profile Created Successfully !!");
    }
    else
    {
        printf("\n\n\t!! Oopps !! .... Password Not Matched .....");
    }
}

void readadmin()
{
    int fileempty = 0;
    FILE *admin = fopen("Admin.txt", "r");

    a = head_adm;
    fseek(admin, 0, SEEK_END);
    if (a == NULL)
    {
        a = (struct node_adm *)malloc(sizeof(struct node_adm));
        head_adm = a;
    }

    int len = (int)ftell(admin);

    if (len <= 0)
    {
        fileempty = 1;
        a = NULL;
        head_adm = a;
    }

    if (fileempty == 0)
    {

        rewind(admin);
        while (fscanf(admin, "%s\t%s\n", a->adname, a->adpassword))
        {
            //printf("%s  %s " , a->adname , a->adpassword);
            if (feof(admin))
            {
                break;
            }

            a->next = (struct node_adm *)malloc(sizeof(struct node_adm));
            a = a->next;
            last_adm = a;
            a->next = NULL;
        }
    }
}

void writeadmin()
{
    FILE *ppy = fopen("Admin.txt", "w");

    a = head_adm;
    if (a == NULL)
    {
        printf("list is empty");
    }
    else
    {
        for (int i = 0; a != NULL; i++)
        {
            fprintf(ppy, "%s\t%s\n", a->adname, a->adpassword);
            a = a->next;
        } //for
    }     //else
    fclose(ppy);
}

void deleteadmin()
{
    struct node_adm *d;
    readadmin();
    int loc, i;
    displayadmin();
    a = head_adm;
    printf("\n\nEnter the location to Delete:\t");
    scanf("%d", &loc);

    if (a != NULL)
    {
        if (loc == 1)
        {
            a = head_adm;
            head_adm = head_adm->next;
            writeadmin();
            free(a);
            return;
        }
        else
        {
            d = head_adm;
        }

        for (int i = 1; i < loc; i++)
        {
            a = d;
            d = d->next;
        }

        a->next = d->next;
        writeadmin();
        free(d);
        n = n - 1;
    }
    else
    {
        printf("\nSorry,The list is empty");
    }
    displayadmin();
}

void displayadmin()
{
    readadmin();
    a = head_adm;

    if (a == NULL)
    {
        printf("list is empty");
    }
    else
    {
        for (int i = 0; a != NULL; i++)
        {
            printf("\n\tAdmin Name:\t"); //source of travel
            printf("%s", a->adname);
            // printf("\t\tPassword:\t\t"); //source of travel
            // printf("%s", a->adpassword);

            a = a->next;
        }
    }
}


void railwaydatabase()
{
    do
    {
        system("CLS");
        printf("\n--------------------------------------------------------\n");
        printf("                    RAILWAY DATABASE MENU                   ");
        printf("\n--------------------------------------------------------\n\n");
        printf("\t1. Add trains \n");
        printf("\t2. Insert train at specific location\n");
        printf("\t3. Sort the trains\n");
        printf("\t4. Delete the trains \n");
        printf("\t5. Search the trains \n");
        printf("\t6. Display the trains \n");
        printf("\t0. EXIT\n");

        printf("\n--------------------------------------------------------\n");
        printf("Choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            exit(0);
            break;

        case 1:
            system("CLS");
            inserttrains();
            break;

        case 2:
            system("CLS");
            displaytrains();
            inserttrainsbw();
            break;

        case 3:
            system("CLS");
            sorttrains();
            displaysortedtrains();
            break;

        case 4:
            system("CLS");
            displaysortedtrains();
            deletetrains();
            break;

        case 5:
            system("CLS");
            displaysortedtrains();
            searchtrains();
            break;

        case 6:
            system("CLS");
            specialtraindisplay();
            break;
        }
        printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Railway Database Menu] (y/n):\t");
        scanf("%s", &ch2);
        strlwr(ch2);
    } while ((strcmp(ch2, ch1)) == 0);
}

void inserttrains()
{
    do
    {
        readdatabase();
        found = 0;
        t = head_train;

        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf("Train No   ||   Source   ||   Destination   || Train name ||  Distance(KM) ||Arr.time(Hrs)||Dept.time(Hrs)||Duration||");
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
        scanf("\t%d %s %s %s %f %f %f %f", &(obj.tno), obj.src, obj.dest, obj.tna, &(obj.km), &(obj.arr), &(obj.dept), &(obj.ttt));
        strlwr(obj.src), strlwr(obj.dest), strlwr(obj.tna);

        for (int i = 1; t != NULL; i++)
        {
            if (t->tno == obj.tno)
            {
                printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %.2f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
                found = 1;
                printf("\n\n\t\t Oopps  !!!  Train Already Present ....\n");
            }
            t = t->next;
        }
    } while (found == 1);

    //struct node *p;
    //int i=0;

    t = last_train;

    if (last_train == NULL)
    {
        //i=1;

        last_train = (struct node_train *)malloc(sizeof(struct node_train));
        last_train->next = NULL;

        last_train->tno = obj.tno;
        strcpy(last_train->src, obj.src);
        strcpy(last_train->dest, obj.dest);
        strcpy(last_train->tna, obj.tna);
        last_train->km = obj.km;
        last_train->arr = obj.arr;
        last_train->dept = obj.dept;
        last_train->ttt = obj.ttt;
        t = last_train;
        head_train = last_train;
    }
    else
    {
        //i=0;
        t = last_train;
        t->next = (struct node_train *)malloc(sizeof(struct node_train));
        t = t->next;
        last_train = t;

        t->tno = obj.tno;
        strcpy(t->src, obj.src);
        strcpy(t->dest, obj.dest);
        strcpy(t->tna, obj.tna);
        t->km = obj.km;
        t->arr = obj.arr;
        t->dept = obj.dept;
        t->ttt = obj.ttt;
        t->next = NULL;
    }
    writedatabase();
    printf("\n\n\t\tTrain Added Successfully ....!!!!!!!\n");
}

void readdatabase()
{
    int i, filempty = 0;
    FILE *infile = fopen("Railway_database.txt", "r");
    t = head_train;

    fseek(infile, 0, SEEK_END);
    if (t == NULL)
    {
        t = (struct node_train *)malloc(sizeof(struct node_train));
        head_train = t;
    }

    int len = (int)ftell(infile);
    if (len <= 0)
    {
        filempty = 1;
        printf("File empty");
        t = NULL;
        head_train = t;
    }

    if (filempty == 0)
    {
        rewind(infile);
        while (fscanf(infile, "\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %f", &(t->tno), t->src, t->dest, t->tna, &(t->km), &(t->arr), &(t->dept), &(t->ttt)))
        {
            if (feof(infile))
            {
                break;
            }
            t->next = (struct node_train *)malloc(sizeof(struct node_train));
            t = t->next;
            last_train = t;
            t->next = NULL;
        }
    }
}

void writedatabase()
{
    FILE *ne = fopen("Railway_database.txt", "w");
    int i;

    t = head_train;

    if (t == NULL)
    {
        printf("Empty File");
    }
    else
    {
        for (i = 0; t != NULL; i++)
        {
            fprintf(ne, "\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
            t = t->next;
        }
    }

    fclose(ne);
}

void displaytrains()
{
    readdatabase();
    t = head_train;

    if (t == NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

        for (int i = 0; t != NULL; i++)
        {
            printf("\n %d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
            t = t->next;
        }
    }
}

void inserttrainsbw()
{
    readdatabase();
    int i, loc;
    int tno;
    char tna[100], src[50], dest[50];
    float arr, dept, km, ttt;

    printf("\n\nEnter the position:");
    scanf("%d", &loc);

    do
    {
        readdatabase();
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf("Train No   ||   Source   ||   Destination   || Train name ||  Distance(KM) ||Arr.time(Hrs)||Dept.time(Hrs)||Duration||");
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
        scanf("\t%d %s %s %s %f %f %f %f", &(tno), src, dest, tna, &(km), &(arr), &(dept), &(ttt));
        strlwr(src), strlwr(dest), strlwr(tna);
        found = 0;
        t = head_train;

        for (i = 1; t != NULL; i++)
        {
            if (t->tno == tno)
            {
                printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
                found = 1;
                printf("\n\t\t Oopps  !!!  Train Already Present ....\n");
            }
            t = t->next;
        }
    } while (found == 1);

    t = head_train;
    //q = head_train;

    struct node_train *q;
    q = (struct node_train *)malloc(sizeof(struct node_train));
    q->tno = tno;
    strcpy(q->src, src);
    strcpy(q->dest, dest);
    strcpy(q->tna, tna);
    q->km = km;
    q->arr = arr;
    q->dept = dept;
    q->ttt = ttt;
    q->next = NULL;

    if (loc == 1)
    {
        q->next = head_train;
        head_train = q;
        writedatabase();
        return;
    }

    for (i = 1; i < loc - 1; i++)
    {
        if (t != NULL)
        {
            t = t->next;
        }
    }
    q->next = t->next;
    t->next = q;
    n = n + 1;

    writedatabase();
    printf("\n\n\t\tTrain Added Successfully ....!!!!!!!\n");
}

void sorttrains()
{
    int k;
    readdatabase();
    int temp;
    struct node_train *i, *j;

    for (i = head_train; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if ((i->tno) > (j->tno)) //write integer variable only in place of data
            {
                obj.tno = i->tno;
                obj.km = i->km;
                obj.arr = i->arr;
                obj.dept = i->dept;
                obj.ttt = i->ttt;

                i->tno = j->tno;
                i->km = j->km;
                i->arr = j->arr;
                i->dept = j->dept;
                i->ttt = j->ttt;

                j->tno = obj.tno;
                j->km = obj.km;
                j->arr = obj.arr;
                j->dept = obj.dept;
                j->ttt = obj.ttt;

                strcpy(obj.src, i->src);
                strcpy(i->src, j->src);
                strcpy(j->src, obj.src);

                strcpy(obj.dest, i->dest);
                strcpy(i->dest, j->dest);
                strcpy(j->dest, obj.dest);

                strcpy(obj.tna, i->tna);
                strcpy(i->tna, j->tna);
                strcpy(j->tna, obj.tna);
            }
        }
    }
    writesorteddb();
}

void writesorteddb()
{
    FILE *ne = fopen("Sorted_Railway_database.txt", "w");
    int i;
    t = head_train;

    if (t == NULL)
    {
        printf("list is empty");
    }
    else
    {
        for (int i = 0; t != NULL; i++)
        {
            fprintf(ne, "\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
            t = t->next;
        }
    }
    fclose(ne);
}

void readsorteddb()
{
    int i, filempty = 0;
    FILE *infile = fopen("Sorted_Railway_database.txt", "r");
    t = head_train;

    fseek(infile, 0, SEEK_END);
    if (t == NULL)
    {
        t = (struct node_train *)malloc(sizeof(struct node_train));
        head_train = t;
    }

    int len = (int)ftell(infile);
    if (len <= 0)
    {
        filempty = 1;
        printf("File empty");
        t = NULL;
        head_train = t;
    }

    if (filempty == 0)
    {
        rewind(infile);
        while (fscanf(infile, "\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %f", &(t->tno), t->src, t->dest, t->tna, &(t->km), &(t->arr), &(t->dept), &(t->ttt)))
        {
            if (feof(infile))
            {
                break;
            }
            t->next = (struct node_train *)malloc(sizeof(struct node_train));
            t = t->next;
            last_train = t;
            t->next = NULL;
        }
    }
}

void displaysortedtrains()
{
    readsorteddb();
    int i;
    t = head_train;

    if (t == NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");
        for (int i = 0; t != NULL; i++)
        {
            printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
            t = t->next;
        }
    }
}

void deletetrains()
{
    struct node_train *q;
    readsorteddb();
    t = head_train;
    int loc, i;

    printf("\n\nEnter the location to delete:\t");
    scanf("%d", &loc);

    if (t != NULL)
    {
        if (loc == 1)
        {
            t = head_train;
            head_train = head_train->next;
            writesorteddb();
            displaysortedtrains();
            free(t);
            return;
        }
        else
        {
            t = head_train;
        }

        q = t;
        for (int i = 1; i < loc; i++)
        {
            q = t;
            t = t->next;
        }
        q->next = t->next;
        writesorteddb();
        displaysortedtrains();
        free(t);
        n = n - 1;
    }
    else
    {
        printf("\nSorry,The list is empty");
    }
}

void searchtrains()
{
    readsorteddb();
    int tno, found = 0;
    float ttt;
    char tna[100], src[50], dest[50];
    t = head_train;

    do
    {
        system("CLS");
        printf("\n--------------------------------------------------------\n");
        printf("                       SEARCH MENU                      ");
        printf("\n--------------------------------------------------------\n\n");
        printf("\t1. Train Number \n");
        printf("\t2. Source\n");
        printf("\t3. Destination\n");
        printf("\t4. Train Name\n");
        printf("\t0. EXIT\n");
        printf("\n--------------------------------------------------------\n");
        printf("Choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            system("CLS");
            readsorteddb();
            t = head_train;
            found = 0;

            printf("\n\nEnter the Train No:\t");
            scanf("%d", &tno);

            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

            for (int i = 1; t != NULL; i++)
            {
                if (t->tno == tno)
                {
                    printf("\n %d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
                    found = 1;
                }
                t = t->next;
            }

            if (!found)
            {
                printf("\n\t Oops !!!! Data not found\n");
            }
            break;

        case 2:
            system("CLS");
            readsorteddb();
            found = 0;
            t = head_train;

            printf("\n\nEnter the Source:\t");
            scanf("%s", src);
            strlwr(src);

            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

            for (int i = 1; t != NULL; i++)
            {
                if (strcmp(t->src, src) == 0)
                {
                    printf("\n %d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
                    found = 1;
                }
                t = t->next;
            }

            if (!found)
            {
                printf("\n\t Oops !!!! Data not found\n");
            }
            break;

        case 3:
            system("CLS");
            readsorteddb();
            t = head_train;
            found = 0;

            printf("\n\nEnter the Destination:\t");
            scanf("%s", dest);
            strlwr(dest);

            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

            for (int i = 1; t != NULL; i++)
            {
                if (strcmp(t->dest, dest) == 0)
                {
                    printf("\n %d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
                    found = 1;
                }
                t = t->next;
            }

            if (!found)
            {
                printf("\n\t Oops !!!! Data not found\n");
            }
            break;

        case 4:
            system("CLS");
            readsorteddb();
            t = head_train;
            found = 0;

            printf("\n\nEnter the Train Name:\t");
            scanf("%s", tna);
            strlwr(tna);

            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

            for (int i = 1; t != NULL; i++)
            {
                if (strcmp(t->tna, tna) == 0)
                {
                    printf("\n %d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
                    found = 1;
                }
                t = t->next;
            }

            if (!found)
            {
                printf("\n\t Oops !!!! Data not found\n");
            }
            break;
        }
        printf("\n---------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Search Menu] (y/n):\t");
        scanf("%s", &ch2);
        strlwr(ch2);
    } while ((strcmp(ch2, ch1)) == 0);
}

void specialtraindisplay()
{
    do
    {
        system("CLS");
        printf("\n--------------------------------------------------------\n");
        printf("                    DISPLAY MENU                      ");
        printf("\n--------------------------------------------------------\n\n");
        printf("\t1. Unsorted trains \n");
        printf("\t2. Sorted trains\n");
        printf("\t0. EXIT\n");
        printf("\n--------------------------------------------------------\n");
        printf("Choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            system("CLS");
            displaytrains();
            break;

        case 2:
            system("CLS");
            displaysortedtrains();
            break;
        }
        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Display Menu] (y/n):\t");
        scanf("%s", &ch2);
        strlwr(ch2);
    } while ((strcmp(ch2, ch1)) == 0);
}


void trainenquiry()
{
    readsorteddb();
    int found = 0;
    char dot[50], src[50], dest[50];
    t = head_train;

    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("                                        TRAIN ENQUIRY                                          ");
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n\nEnter the Source      :\t");
    scanf("%s", src);
    strlwr(src);
    printf("Enter the Destination :\t");
    scanf("%s", dest);
    strlwr(dest);
    //printf("\n\nEnter the date of travel(dd/mm/yyyy):\t");
    //scanf("%s",dot);

    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

    for (int i = 1; t != NULL; i++)
    {
        if ((strcmp(t->src, src) == 0) && (strcmp(t->dest, dest) == 0))
        {
            printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
            found = 1;
        }
        t = t->next;
    }

    if (!found)
    {
        printf("\n\t Oops !!!! No trains found\n");
    }
}


void book()
{
    //read();
    int valid;
    char dateStr[10];
    struct node_user *u;
    int i = 0, choice;
    head_user = NULL;
    u = head_user;

    if (u == NULL)
    {
        i = 1;
        u = (struct node_user *)malloc(sizeof(struct node_user));
        u->next = NULL;
        head_user = u;
        printf("\n\tSource                              :\t"); //source of travel
        scanf("%s", u->source);
        strlwr(u->source);
        printf("\tDestination                         :\t"); //destination of travel
        scanf("%s", u->destination);
        strlwr(u->destination);

        do
        {
            _strdate(dateStr);
            printf("\tSystem Date                         :\t%s", dateStr);
            printf("\n\tEnter the Date of travel(mm/dd/yy)  : ");
            scanf("\t%s", u->date);
            if (strcmp((u->date), dateStr) <= 0)
            {
                printf("\n\t\t Invalid Date .....!!!!!!\n");
            }
        } while (strcmp((u->date), dateStr) <= 0);

        //system("CLS");
        //printf("\n----------------------------------------------------------------------------\n");
        printf("\tTotal Number of passenger           : ");
        scanf("%d", &(u->adult));

        printf("\nPASSENGER DETAILS : ");

        int nop = u->adult;
        for (int i = 1; i <= nop; i++)
        {
            printf("\n\tEnter the Name of Passenger %d :\t", i);
            scanf(" %[^\n]s", u->name);
            strlwr(u->name);

            printf("\tAge                           :\t");
            scanf("%d", &(u->age));

            printf("\tGender(M/F)                   :\t");
            scanf("%s", u->gender);
            strupr(u->gender);

            //Mobile Number
            do
            {
                printf("\tMobile No                     :\t");
                scanf("%s", u->mobno);

                if (strlen(u->mobno) != 10)
                {
                    printf("\n\t\tInvalid MOBILE NO ....!!!!!!!\n");
                }
            } while (strlen(u->mobno) != 10);

            printf("\tEmail id                      :\t");
            scanf("%s", u->email);
            strlwr(u->email);

            //UID
            do
            {
                printf("\tIdentification no (Aadhar no./PAN no./Voting card no.)           : ");
                scanf("%s", u->idno);

                if (strlen(u->idno) != 10)
                {
                    printf("\n\t\tInvalid ID NO ....!!!!!!!\n");
                }
            } while (strlen(u->idno) != 10);

            printf("\tClass of travel (Sleeper = SL , AC 2 Tier = 2AC , AC 3 Tier=3AC) : ");
            scanf("%s", u->clas);
            strupr(u->clas);

            last_user = u;
            u->next = (struct node_user *)malloc(sizeof(struct node_user));
            u = u->next;
            u->next = NULL;
        }
    }

    system("cls");
    printf("\n----------------------------------------------------------------------------\n");
    printf("\n\n1. CONFIRM BOOKING \n2. EDIT TICKET \n3. CANCEL BOOKING\n Choice: ");
    scanf("%d", &choice);
    printf("\n----------------------------------------------------------------------------\n");
    
    switch (choice)
    {
    case 1:
        write();
        break;
    case 2:
        display();
        printf("\n---------------------------------------");
        printf("\nDo You Want to edit the ticket (y/n):");
        scanf("%s", &ch2);
        strlwr(ch2);
        if ((strcmp(ch1, ch2)) == 0)
        {
            book();
        }
        else
        {
            break;
        }
        break;
    case 3:
        exit(0);
        break;
    }
}

void read()
{
    int i, filempty = 0;
    FILE *infile = fopen("Ticket_booking.txt", "r");
    u = head_user;
    fseek(infile, 0, SEEK_END);

    if (u == NULL)
    {
        u = (struct node_user *)malloc(sizeof(struct node_user));
        head_user = u;
    }

    int len = (int)ftell(infile);
    if (len <= 0)
    {
        filempty = 1;
        printf("\nFile empty\n");
        u = NULL;
        head_user = u;
    }

    if (filempty == 0)
    {
        rewind(infile);
        while (fscanf(infile, "%s\n", u->source),
               fscanf(infile, "%s\n", u->destination),
               fscanf(infile, "%s\n", u->date),
               fscanf(infile, "%d\n", &u->adult),
               fscanf(infile, "%s\n", u->name),
               fscanf(infile, "%d\n", &u->age),
               fscanf(infile, "%s\n", u->gender),
               fscanf(infile, "%s\n", u->mobno),
               fscanf(infile, "%s\n", u->email),
               fscanf(infile, "%s\n", u->idno),
               fscanf(infile, "%s\n", u->clas))
        {
            if (feof(infile))
            {
                break;
            }
            u->next = (struct node_user *)malloc(sizeof(struct node_user));
            u = u->next;
            last_user = u;
            u->next = NULL;
        }
    }
}

void write()
{
    u = head_user;
    //FILE *ne = fopen("Ticket_booking.txt", "w");
    filepath1[200] = "D:\\Shubham\\Study Material\\2nd Year\\2nd SEM\\DS\\Lab\\Course Project\\Project\\Passenger Details\\" ;
    char str1[30] , str2[10] = ".txt";
    strcpy(str1,u->name);
    strcat(str1,str2);
    strcat(filepath1,str1);
    FILE *ne = fopen(filepath1, "w");
    int i;
    struct node_user *u;
    u = head_user;
    if (u == NULL)
    {
        printf("list is empty");
    }
    else
    {
        // ("\n\t DATA IS BEING SAVED IN DATABASE\n");
        for (i = 0; u->next != NULL; i++)
        {
            if (i == 0)
            {
                fprintf(ne, "Source      :%s\n", u->source);
                fprintf(ne, "Destination :%s\n", u->destination);
                fprintf(ne, "Date        :%s\n", u->date);
                fprintf(ne, "No. of Passengers : %d\n", u->adult);
            }
            fprintf(ne, "\nName            :%s\n", u->name);
            fprintf(ne, "Age             :%d\n", u->age);
            fprintf(ne, "Gender          :%s\n", u->gender);
            fprintf(ne, "Mobile No       :%s\n", u->mobno);
            fprintf(ne, "Email ID        :%s\n", u->email);
            fprintf(ne, "ID No           :%s\n", u->idno);
            fprintf(ne, "Class of Travel :%s\n", u->clas);
            u = u->next;
        } //for
        printf("\n\t----- DONE ----- DATA SAVED SUCCESSFULLY\n");
    } //else
    fclose(ne);
}

void display1()
{
    int i;
    u = head_user;
    if (u == NULL)
    {
        printf("list is empty");
    }
    else
    {
        for (i = 0; u->next != NULL; i++)
        {
            printf("\n\tSource                               : "); //source of travel
            printf("%s", u->source);
            printf("\n\tDestination                          : "); //destination of travel
            printf("%s", u->destination);
            printf("\n\tEnter the Date of travel(dd/mm/yyyy) : ");
            printf("%s", u->date);
            //printf("\n----------------------------------------------------------------------------\n");
            printf("\tTotal Number of passenger              : ");
            printf("%d", (u->adult));

            printf("\n");
            printf("\n----------------------------------------------------------------------------\n");
            printf("                             PASSENGER Details                   ");
            printf("\n----------------------------------------------------------------------------\n");
            printf("\n\t Passenger Name:\t");
            printf("%s", u->name);
            printf("\n\tAge:\t\t");
            printf("%d", (u->age));
            printf("\n\tGender(M/F):\t\t");
            printf("%s", u->gender);
            printf("\n\tMobile No:\t\t");
            printf("%s", u->mobno);
            printf("\n\tEmail id:\t\t");
            printf("%s", u->email);
            printf("\n\tIdentification no\n (Aadhar no./PAN no./Voting card no.):\t\t");
            printf("%s", u->idno);
            printf("\n\tClass of travel\n (Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t\t");
            printf("%s", u->clas);

            u = u->next;
        }
    }
}

void trainselect()
{
    char temp1[50], temp2[50];
    system("CLS");
    //read();
    int i, found = 0;
    u = head_user;
    if (u == NULL)
    {
        printf("File is Empty:");
    }
    else
    {
        for (i = 0; u != NULL; i++)
        {
            printf("\n\tSource      :\t"); //source of travel
            printf("%s", u->source);
            strcpy(temp1, u->source);
            printf("\n\tDestination :\t"); //destination of travel
            printf("%s", u->destination);
            strcpy(temp2, u->destination);
            break;
        }
    }

    readsorteddb();
    t = head_train;
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

    for (i = 1; t != NULL; i++)
    {
        if ((strcmp(t->src, temp1) == 0) && (strcmp(t->dest, temp2) == 0))
        {
            printf("\n%d\t %s\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %.2f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
            found = 1;
        }
        t = t->next;
    }

    if (!found)
    {
        printf("\n\t Oops !!!! No trains found\n\n");
    }
}

void payout()
{
    int ptno, ch;
    //float pkm, fare, afare, tfare;
    char choice3[] = "y", choice[10], a[] = "SL", b[] = "3AC", c[] = "2AC";
    int SL = 10, AC3 = 15, AC2 = 12;

    FILE *as;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
    do
    {
        printf("\nSelect the train No : ");
        scanf("%d", &ptno);

        u = head_user;
        u->ptno = ptno;

        payoutwrite();
        readdatabase();
        found = 0;
        t = head_train;
        system("cls");
        for (i = 1; t != NULL; i++)
        {
            if (t->tno == ptno)
            {
                printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
                printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

                printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %.2f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
                pkm = t->km;
                found = 1;
            }
            t = t->next;
        }
        if (!found)
        {
            printf("\n\t\t Enter Valid Train no ....\n");
            found = 3;
        }
    } while (found == 3);

    int temp3;
    char temp5[10], temp6[10];
    //read();
    int i, found = 0;
    u = head_user;
    if (u == NULL)
    {
        printf("File is Empty:");
    }
    else
    {
        for (i = 0; u != NULL; i++)
        {
            printf("\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\nPassengers                                    : "); //source of travel
            printf("%d", u->adult);
            temp3 = u->adult;

            strcpy(temp5, u->clas);

            if (strcmp(temp5, a) == 0)
            {
                afare = (pkm * temp3 * SL);
            }

            if (strcmp(temp5, b) == 0)
            {
                afare = (pkm * temp3 * AC3);
            }

            if (strcmp(temp5, c) == 0)
            {
                afare = (pkm * temp3 * AC2);
            }

            fare = afare;

            //printf("\n\tAdult fare:%.2f\t\t",afare);
            printf("\nTotal fare(Without Ins)                       : %.2f", fare);
            printf("\nWant to take insurance(y/n) Rs 1/Passenger    : ");
            scanf("%s", choice);
            if (strcmp(choice3, choice) == 0)
            {
                tfare = (temp3 * 1) + fare;
                printf("Total fare(With Ins)                          : %.2f\t\t", tfare);
            }
            else
            {
                tfare = fare;
                printf("\n\tTotal fare(Without Ins):%.2f\t\t", tfare);
            }

            printf("\n\n------------------------------------------------------------------------\n");
            printf("\t1. Pay Now \t\t2. Cancel & EXIT\n");
            printf("------------------------------------------------------------------------\n");
            printf("\tChoice : ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:{
                filepath2[200] = "D:\\Shubham\\Study Material\\2nd Year\\2nd SEM\\DS\\Lab\\Course Project\\Project\\Booking Receipt\\" ;
                char str1[30] = "_booking_receipt.txt";
                char str2[30];
                strcpy(str2,u->name);
                strcat(str2,str1);
                strcat(filepath2 , str2);
                printf("\n Train_no                : %d\n Source                  : %s\n Destination             : %s\n Date                    : %s\n Total_fare(Without_Ins) : %.2f\n Total_fare(With_Ins)    : %.2f\n ", ptno , u->source , u->destination , u->date , fare, tfare);
                
                as = fopen(filepath2, "w");
                fprintf(as, "\n Train_no                : %d\n Source                  : %s\n Destination             : %s\n Date                    : %s\n Total_fare(Without_Ins) : %.2f\n Total_fare(With_Ins)    : %.2f\n ", ptno , u->source , u->destination , u->date , fare, tfare);
                fclose(as);
                //printf("\n------------------------------------------------------------------------\n");
                printf("\t\t\n!!  Payment Successfully Done  !!\n");
                //printf("\n------------------------------------------------------------------------\n");
                break;
            }

            case 2:
                exit(0);
                break;
            }
            break;
        }
    }
}

void payoutwrite()
{
    FILE *py = fopen("Booking.txt", "a");
    int i;
    u = head_user;
    fseek(py,0,SEEK_END);
    if (u == NULL)
    {
        printf("list is empty");
    }
    else
    {
        fprintf(py, "\n%d", u->ptno);
    }     //else
    fclose(py);
}

void display()
{
    //read();
    int i;
    u = head_user;
    if (u == NULL)
    {
        printf("list is empty");
    }
    else
    {
        for (i = 0; u->next != NULL; i++)
        {
            if (i == 0)
            {
                printf("\n\tSource                               : "); //source of travel
                printf("%s", u->source);
                printf("\n\tDestination                          : "); //destination of travel
                printf("%s", u->destination);
                printf("\n\tEnter the Date of travel(dd/mm/yyyy) : ");
                printf("%s", u->date);
                //printf("\n----------------------------------------------------------------------------\n");
                printf("\n\tTotal Number of passenger            : ");
                printf("%d", (u->adult));

                printf("\n");
                printf("\n\nPASSENGER DETAILS : ");
            }

            printf("\n\tPassenger Name        : ");
            printf("%s", u->name);
            printf("\n\tAge                   : ");
            printf("%d", (u->age));
            printf("\n\tGender(M/F)           : ");
            printf("%s", u->gender);
            printf("\n\tMobile No             : ");
            printf("%s", u->mobno);
            printf("\n\tEmail id              : ");
            printf("%s", u->email);
            printf("\n\tIdentification no (Aadhar no./PAN no./Voting card no.)         : ");
            printf("%s", u->idno);
            printf("\n\tClass of travel (Sleeper=SL , AC 2 Tier=2AC , AC 3 Tier = 3AC) :");
            printf("%s", u->clas);
            printf("\n");
            u = u->next;
        }
    }
}

void displaysearchtrainticket()
{
    //payoutread();
    int ptno;
    u = head_user;
    ptno = u->ptno;
    i = 0, found = 0;

    readsorteddb();
    t = head_train;
    printf("\n\nBOOKED TRAIN : ");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("TrainNo|| Source ||  Destination  ||    Train name    ||    Distance(KM)   || Arr. time(Hrs) ||   Dept. time(Hrs)   ||  Duration  ||");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n   ");

    for (i = 1; t != NULL; i++)
    {
        if (t->tno == ptno)
        {
            printf("\n %d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %f", (t->tno), t->src, t->dest, t->tna, t->km, t->arr, t->dept, (t->ttt));
            found = 1;
        }
        t = t->next;
    }
}
