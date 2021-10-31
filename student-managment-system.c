#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void gotoxy(int, int);
void menu();
void add();
void view();
void search();
void modify();
void deleterec();

struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};

int main()
{
    gotoxy(15, 8);
    printf("|:::|  YZU Student Management System  |:::|");
    gotoxy(19, 15);
    printf("\tPress any key to continue: ");
    getch();
    menu();
    return 0;
}

void menu()
{
    int choice;
    system("cls");
    gotoxy(10, 3);
    printf("===| MENU |===");
    gotoxy(10, 5);
    printf("Enter any of the following number to perform the task.");
    gotoxy(10, 7);
    printf("1. Insert Info");
    gotoxy(10, 8);
    printf("2. View Info");
    gotoxy(10, 9);
    printf("3. Search Info");
    gotoxy(10, 10);
    printf("4. Modify Info");
    gotoxy(10, 11);
    printf("5. Delete Info");
    gotoxy(10, 12);
    printf("6. Exit");
    gotoxy(10, 15);

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        view();
        break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        deleterec();
        break;
    case 6:
        exit(1);
        break;
    default:
        gotoxy(10, 17);
        printf("Invalid Choice.");
    }
}

void add()
{
    FILE *fp;
    struct student std;
    char another = 'y';
    system("cls");

    fp = fopen("record.txt", "ab+");
    if (fp == NULL)
    {
        gotoxy(10, 5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        gotoxy(10, 3);
        printf("===| ADD INFORMATION |===");
        gotoxy(10, 5);
        printf("Enter details of student.");
        gotoxy(10, 7);
        printf("Enter Name : ");
        //        gets(std.name);///???
        gets(std.name);
        gotoxy(10, 8);
        printf("Enter Gender : "); // mobile
        gets(std.mobile);
        gotoxy(10, 9);
        printf("Enter Student ID : "); // roll
        scanf("%d", &std.rollno);
        fflush(stdin);
        gotoxy(10, 10);
        printf("Enter Class : "); // course
                                  //        gets(std.course);///???
        gets(std.course);
        gotoxy(10, 11);
        printf("Enter Year-Of-Birth : "); // grade
        gets(std.branch);
        //        gotoxy(10,12);
        //        printf("Enter Father's Name : ");
        //        gets(std.fathername);
        fwrite(&std, sizeof(std), 1, fp);
        gotoxy(10, 15);
        printf("Want to add of another record?Then press 'y' else 'n'.");
        fflush(stdin);
        //        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10, 18);
    printf("Press any key to continue.");
    getch();
    menu();
}

void view()
{
    FILE *fp;
    int i = 1, j;
    struct student std;
    system("cls");
    gotoxy(10, 3);
    printf("===| VIEW INFORMATION |===");
    gotoxy(10, 5);
    printf("--------------------------------------------------------------");
    gotoxy(10, 6);
    printf("S.No   Student     Gender   Student-ID     Class    Birth-Year");
    gotoxy(10, 7);
    printf("--------------------------------------------------------------");
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 8);
        printf("Error opening file.");
        exit(1);
    }
    j = 8;
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {
        gotoxy(10, j + 1);
        printf(" %-6d%-12s%-9s%-15d%-10s%-10s", i, std.name, std.mobile, std.rollno, std.course, std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10, j + 5);
    printf("Press any key to continue: ");
    getch();
    menu();
}

void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    gotoxy(10, 3);
    printf("===| SEARCH INFORMATION |===");
    gotoxy(10, 5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {
        if (strcmp(stname, std.name) == 0)
        {
            gotoxy(10, 8);
            printf("Name : %s", std.name);
            gotoxy(10, 9);
            printf("Gender : %s", std.mobile);
            gotoxy(10, 10);
            printf("Student ID : %d", std.rollno);
            gotoxy(10, 11);
            printf("Class : %s", std.course);
            gotoxy(10, 12);
            printf("Year-of-Birth : %s", std.branch);
        }
    }
    fclose(fp);
    gotoxy(10, 16);
    printf("Press any key to continue: ");
    getch();
    menu();
}

void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10, 3);
    printf("===| MODIFY INFORMATION |===");
    gotoxy(10, 5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {
        if (strcmp(stname, std.name) == 0)
        {
            gotoxy(10, 7);
            printf("Enter Name: ");
            gets(std.name);
            gotoxy(10, 8);
            printf("Enter Gender : ");
            gets(std.mobile);
            gotoxy(10, 9);
            printf("Enter Student ID : ");
            scanf("%d", &std.rollno);
            gotoxy(10, 10);
            printf("Enter Class : ");
            fflush(stdin);
            gets(std.course);
            gotoxy(10, 11);
            printf("Enter Year-of-Birth : ");
            fflush(stdin);
            gets(std.branch);
            fseek(fp, -sizeof(std), SEEK_CUR);
            fwrite(&std, sizeof(std), 1, fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10, 16);
    printf("Press any key to continue: ");
    getch();
    menu();
}

void deleterec()
{
    char stname[20];
    FILE *fp, *ft;
    struct student std;
    system("cls");
    gotoxy(10, 3);
    printf("===| DELETE RECORD |===");
    gotoxy(10, 5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt", "wb+");
    if (ft == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {
        if (strcmp(stname, std.name) != 0)
            fwrite(&std, sizeof(std), 1, ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    gotoxy(10, 10);
    printf("Press any key to continue: ");
    getch();
    menu();
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
