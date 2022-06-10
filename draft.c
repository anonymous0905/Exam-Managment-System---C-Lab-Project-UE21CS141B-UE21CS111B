#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int option = 0;
int i = 0;
int n = 0;
int j = 0;
float present = 85.00;
char fee = 'P';
float tdays = 1;

struct student {
    char name[20];
    int rno;
    char fees;
    float days;
    float attend;
} s[50];

void add(struct student s[50]);
void delete (struct student s[]);
void eligibleStudents(struct student s[]);
void execute();
void print_student(struct student s[]);

void add(struct student s[50])
{
    printf("Enter total number of working days \n");
    scanf("%f", &tdays);

    printf("Enter the number of students \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        printf("Student number %d \n",(i + 1));
        printf("Enter the name of the student \n");
        scanf("%s", s[i].name);
        printf("Enter the roll number \n");
        scanf(" %d", &s[i].rno);
        printf("Enter fee status P/N/B \n");
        scanf(" %c", &s[i].fees);
        printf("Enter the number of days Student was present\n");
        scanf("%f", &s[i].days);

        s[i].attend = (s[i].days/ tdays)* 100;
        printf("student attendance = %f \n",s[i].attend);
    }
    execute();
}

void delete (struct student s[])
{
    int a = 0;
    printf("Enter srn of student to delete \n");
    scanf("%d", &a);

    for (i = 0; i <= n; i++) {

        if (s[i].rno == (a)) {

            for (j = i; j < n; j++) {
                strcpy(s[j].name,s[j + 1].name);
                s[j].rno = s[j + 1].rno;
                s[j].fees = s[j + 1].fees;
                s[j].days = s[j + 1].days;
                s[j].attend = s[j + 1].attend;
            }
            printf("Student Record deleted\n");
        }
    }
}

void eligibleStudents(struct student s[])
{
    printf("\n \n");
    printf("Qualified student are = \n");
    for (i = 0; i < n; i++) {
        if (s[i].fees == fee) {
            if (s[i].attend >= present) {
                printf("Student name = %s \n",s[i].name);

                printf("Student roll no. = %d \n",s[i].rno);

                printf(" Student fees = %c \n",s[i].fees);

                printf(" Student attendence = %f \n",s[i].attend);
            }
        }
    }
}

void execute()
{
    printf("Select from the options below \n");
    printf(" 1. To show Eligible Candidates \n");
    printf(" 2. To delete the student record \n");
    printf(" 3. To change the eligibility criteria \n");
    printf(" 4. Reset the eligibility criteria \n");
    printf(" 5. Print the list of all the student \n");
    printf(" Enter 0 to exit \n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            eligibleStudents(s);
            execute();
            break;

        case 2:
            delete(s);
            execute();
            break;

        case 3:
            printf("Old Attendance required = %f \n",present);
            printf("Enter New Attendance Required \n");
            scanf("%f", &present);
            printf("fees status required was %c \n", fee);
            printf("Enter fee status P/N/B\n");
            scanf("%c", &fee);
            printf("Eligibility Criteria updated \n");
            execute();
            break;

        case 4:
            present = 85.00;
            fee = 'P';
            printf("Eligibility Criteria has been reset \n");
            execute();
            break;

        case 5:
            print_student(s);
            execute();
            break;

        case 0:
            exit(0);

        default:
            printf("Please select valid input from 0 to 5 \n");
            execute();
    }
}

void print_student(struct student s[])
{
    for (i = 0; i < n; i++) {
        printf("Name of student %s \n",s[i].name);
        printf("Student roll number = %d \n",s[i].rno);
        printf("Student fees status = %c \n",s[i].fees);
        printf("student number of days present = %d \n",s[i].days);
        printf("Student attendence = %f \n",s[i].attend);
    }
}

int main()
{
    printf("Welcome exam management system \n");

    printf("Enter 0 to exit \n");
    printf("Enter 1 to add student record \n");

    scanf("%d", &option);

    // Switch Statements
    switch (option) {
        case 0:
            exit(0);

        case 1:
            add(s);
            break;

        default:
            printf("Only enter 0 or 1\n");
            execute();
    }
    return 0;
}