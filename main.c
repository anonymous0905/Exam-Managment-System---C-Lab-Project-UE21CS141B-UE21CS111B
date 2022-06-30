#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int option = 0;//choice
int i =0;//counter
int j=0;//counter
float present = 75.0;//attendance percentage required
int twdays = 1;//total number of working days
int roomallotment = 1;


typedef struct student {
    char name[40];//student name
    char srn[20];//student srn
    char class[5];//semester and class
    int fee_total;//fee to be paid
    int fee_paid;//fee paid by student
    int days;//no of days student a
    char room_allotment[10];//exam room allotment
    float attend;//attendance percentage
}std;


int line_check();//to count number of lines in file
void print_students(std s[], int n);// to print details of all students on terminal
void eligible_students(std s[], int n);//to output list of all eligible students in a file
void student_records(std[], int n);//to display records of a particular student
void room_allotment(std s[],int n);//for room allotment
void admit_card_generation(std s[], int n);//for generation of admit cards
int compare(char a[],char b[]);//to compare two strings
void update_attendance(std s[], int n);//to update student attendance
int delete_records(std s[], int n);//to delete student records
void write_tofile(std s[], char fl[][30], int n);//to write the data back to the database
void update_eligibility();//to update attendance eligibility criteria

int main()
{
    printf("Welcome to exam management system\n");
    printf("Enter total number of working days : -\n");
    scanf("%d",&twdays);//inputting total number of working days
    int n = line_check();//to check no of lines in csv file
    if (n==-1)
    {
        exit(0);
    }
    //printf("Check");
    std s[n];//array of struct type
    FILE *fr1 = fopen("student.csv","r");//opening csv file to input data
    if(fr1 == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    //printf("Check");
    char a[500];//buffer
    char *item;
    char *item1;

    char fl[7][30];
    int r = 0;

    while(fgets(a,500,fr1))//reading first line and storing it in a array;
    {
        item1 = strtok(a, ",");
        strcpy(fl[r],item1);
        r+=1;
        item1 = strtok(NULL, ",");
        strcpy(fl[r],item1);
        r+=1;
        item1 = strtok(NULL, ",");
        strcpy(fl[r],item1);
        r+=1;
        item1 = strtok(NULL, ",");
        strcpy(fl[r],item1);
        r+=1;
        item1 = strtok(NULL, ",");
        strcpy(fl[r],item1);
        r+=1;
        item1 = strtok(NULL, ",");
        strcpy(fl[r],item1);
        break;
    }

    int k = 0;//counter
    //printf("Check");

    while(fgets(a,500,fr1))//inputting data to array of struct student
    {
        //printf("Check");
        item = strtok(a, ",");
        strcpy(s[k].name, item);
        //printf("Check");
        item = strtok(NULL, ",");
        strcpy(s[k].srn, item);
        //printf("Check");
        item = strtok(NULL, ",");
        strcpy(s[k].class, item);
        //printf("Check");
        item = strtok(NULL,",");
        s[k].fee_total = atoi(item);
        //strcpy(s[k].fee_total,item);
        //printf("Check");
        item = strtok(NULL,",");
        s[k].fee_paid = atoi(item);
        //strcpy(s[k].fee_paid,item);
        item = strtok(NULL, ",");
        s[k].days = atoi(item);
        int days = atoi(item);
        //printf("%d\n",days);
        s[k].attend = ((float)days/twdays)*100;
        //printf("%f\n",s[k].attend);
        strcpy(s[k].room_allotment,"Not Assigned");
        k++;
    }
    fclose(fr1);//file close

    while(true)
    {
        int m2;
        printf("Select from the below Options:- \n");
        printf("1. Display details of All students on terminal\n");
        printf("2. Output List of Eligible Students to a File\n");
        printf("3. To display Student Details\n");
        printf("4. Exam Room Allotment\n");
        printf("5. Admit Card Generation for Eligible Students\n");
        printf("6. Update Student Attendance\n");
        printf("7. Delete Student Records\n");
        printf("8. Update Exam Eligibility\n");
        printf("9. Update All changes to File\n");
        scanf("%d",&option);

        switch (option) {

            case 1:
                print_students(s,n);
                break;
            case 2:
                eligible_students(s,n);
                break;
            case 3:
                student_records(s,n);
                break;
            case 4:
                room_allotment(s,n);
                break;
            case 5:
                admit_card_generation(s,n);
                break;
            case 6:
                update_attendance(s,n);
                break;

            case 7:
                m2 = delete_records(s, n);
                n = m2;
                write_tofile(s,fl,n);
                break;
            case 8:
                update_eligibility();
                break;
            case 9:
                write_tofile(s,fl,n);
                break;
            case 101:
                write_tofile(s,fl,n);
                printf("Program Terminated\n");
                exit(0);
                break;
            default:
                printf("Please Enter a Valid Choice\n");
                break;
        }
    }

}

void update_eligibility()
{
    printf("Enter Administrator Password\n");
    char inp_psd[30];
    scanf("%s",&inp_psd);
    if(compare(inp_psd,"admin1234")==0)
    {
        printf("Enter New Attendance Criteria\n");
        scanf("%f",&present);//updating attendance percentage required
        printf("Successful\n");
    }
    else
    {
        printf("Error Please try again\n");
    }
}

void write_tofile(std s[], char fl[][30], int n)
{
    FILE *fr4 = fopen("student.csv","w+");

    fprintf(fr4,"%s,%s,%s,%s,%s,%s",fl[0],fl[1],fl[2],fl[3],fl[4],fl[5]);//printing the first line to file

    for(i=0; i<n; i++)
    {
        fprintf(fr4,"%s,%s,%s,%d,%d,%d\n",s[i].name,s[i].srn, s[i].class, s[i].fee_total, s[i].fee_paid,s[i].days);
        //printing the student details to file (seperated by a ',')
    }
    fclose(fr4);
}

void update_attendance(std s[], int n)
{
    char inp_srn[30];
    printf("Enter SRN of Student\n");
    scanf("%s",&inp_srn);
    int flag = 0;

    for(int i=1; i<n; i++)
    {
        if (compare(s[i].srn, inp_srn) == 0)//if srn is found
        {
            printf("Old Attendance %d Days\n",s[i].days);
            printf("Enter New Attendance (Number of days Present) \n");
            scanf("%d",&s[i].days);
            printf("Enter Administrator Password to Confirm\n");
            char inp_psd[30];
            scanf("%s",&inp_psd);
            if(compare(inp_psd,"admin1234")==0)
            {
                s[i].attend = ((float)s[i].days/twdays)*100;
                printf("Successful\n");
                flag =1;
                break;
            }
            else
            {
                printf("Error please try again\n");
            }

        }
    }

    if(flag!=1)
    {
        printf("SRN Not found please try again\n");
    }
}

void admit_card_generation(std s[], int n)
{
    if(roomallotment!=0)
    {
        room_allotment(s,n);
    }

    FILE *fr3 = fopen("Admit_Card.txt","w+");

    if(fr3 == NULL)
    {
        printf("Error Opening File\n");
    }

    else
    {
        printf("Enter Number of Courses\n");
        int nc = 0;
        scanf("%d",&nc);
        char cc[n][30];
        for(i =0; i<nc;i++)
        {
            printf("Enter Course Code\n");
            scanf("%s",&cc[i]);
        }
        for(j =0; j<n; j++)
        {
            if((s[j].fee_total==s[j].fee_paid) && s[j].attend>=present)
            {
                fprintf(fr3, "Name:- %s \nSRN:- %s \nClass:- %s \nAttendance:- %.2f \nRoom Number - %s\n\n", s[j].name,s[j].srn, s[j].class,  s[j].attend,s[j].room_allotment);
                fprintf(fr3,"Courses Enrolled :-\n");
                for(i=0; i<nc; i++)
                {
                    fprintf(fr3, "%s\n", cc[i]);
                }
                fprintf(fr3,"\n-----------------------------------------------------------------------------\n\n");
            }
        }
        printf("Admit Card Generated Successfully\n");

    }

    fclose(fr3);
}

void room_allotment(std s[], int n)
{
    char room[20][20];
    int room1[20];
    int cpy = n;
    int g = 0;

    while(cpy>0)
    {
        printf("Enter Room Number\n");
        scanf("%s",&room[g]);
        printf("Enter Number of seats\n");
        scanf("%d",&room1[g]);
        cpy = cpy - room1[g];
        g++;
        printf("\n");
    }
    //printf("%d",g);

    int d = 0;
    for(i=0; i<n; i++)
    {
        if(room1[d]==0)
        {
            d +=1;
        }
        if(room1[d]>0)
        {
            if((s[i].fee_total==s[i].fee_paid) && s[i].attend>=present)
            {
                strcpy(s[i].room_allotment,room[d]);
                room1[d] -= 1;
            }

        }
    }
    roomallotment = 0;
    printf("Room allotment for Qualified Students Successful\n");


}

void student_records(std s[], int n)
{
    char inp_srn[30];
    printf("Enter SRN of Student\n");
    scanf("%s",&inp_srn);
    int flag = 0;

    for(int i=1; i<n; i++)
    {
        if(compare(s[i].srn,inp_srn)==0)
        {
            fprintf(stdout, "Name - %s\n", s[i].name);
            fprintf(stdout, "SRN - %s\n", s[i].srn);
            fprintf(stdout, "Class - %s\n", s[i].class);
            fprintf(stdout, "Fee to be paid - %d\n", s[i].fee_total);
            fprintf(stdout, "Fee Paid - %d\n", s[i].fee_paid);
            fprintf(stdout, "Number of days present - %d\n", s[i].days);
            fprintf(stdout, "Attendance Percentage - %.2f\n", s[i].attend);
            fprintf(stdout, "-------------------------------------------\n");
            flag = 1;
            break;
        }

    }
    if(flag!=1)
    {
        printf("SRN not Found Please try again\n");
    }
}

int delete_records(std s[], int n)
{
    char inp_srn[30];
    printf("Enter SRN of student\n");
    scanf("%s",&inp_srn);
    int flag = 0;

    for(i =0; i<n; i++)
    {
        if(compare(s[i].srn, inp_srn)==0)
        {
            printf("Please enter admin key to delete student records\n");
            char admin_key[20];
            scanf("%s",&admin_key);
            char key[] = "admin1234";
            if(compare(admin_key,key)==0)
            {
                for (j = i; j < n; j++) {
                    strcpy(s[j].name,s[j + 1].name);
                    strcpy(s[j].srn,s[j + 1].srn);
                    strcpy(s[j].class, s[j+1].class);
                    strcpy(s[j].room_allotment,s[j+1].room_allotment);
                    s[j].fee_total = s[j + 1].fee_total;
                    s[j].fee_paid = s[j + 1].fee_paid;
                    s[j].days = s[j + 1].days;
                    s[j].attend = s[j + 1].attend;
                }
                printf("Student Record deleted\n");
                n= n-1;
                flag = 1;
                return n;

            }
            else
            {
                printf("Failed Authentication please try again\n");
                return n;
            }
        }

    }
    if(flag!=1)
    {
        printf("SRN not Found Please Try Again\n");
    }

}

int compare(char a[],char b[])
{
    int flag=0,h=0;  // integer variables declaration
    while(a[h]!='\0' &&b[h]!='\0')  // while loop
    {
        if(a[h]==b[h])
        {
            h++;
            continue;
        }
        else
        {
            flag = 1;
            break;
        }
        h++;
    }
    if(flag==0)
        return 0;
    else
        return 1;
}

void eligible_students(std s[], int n)
{
    FILE *fr2 = fopen("Qualified_students.txt","w+");
    for(j =0; j<n; j++)
    {
        if((s[j].fee_total==s[j].fee_paid) && s[j].attend>=present)
        {

            fprintf(fr2, "Name:- %s \nSRN:- %s \nClass:- %s \nAttendance:- %.2f \n\n", s[j].name,s[j].srn, s[j].class,  s[j].attend);
        }
    }

    fclose(fr2);
}


void print_students(std s[], int n)
{
    for(i=0; i<n; i++)
    {
        fprintf(stdout, "Name - %s\n", s[i].name);
        fprintf(stdout, "SRN - %s\n", s[i].srn);
        fprintf(stdout, "Class - %s\n", s[i].class);
        fprintf(stdout, "Fee to be paid - %d\n", s[i].fee_total);
        fprintf(stdout, "Fee Paid - %d\n", s[i].fee_paid);
        fprintf(stdout, "Number of days present - %d\n", s[i].days);
        fprintf(stdout, "Attendance Percentage - %.2f\n", s[i].attend);
        fprintf(stdout, "Room Allotment - %s\n", s[i].room_allotment);
        fprintf(stdout, "-------------------------------------------");
        fprintf(stdout, "\n");

    }

}

int line_check()
{
    FILE *fr=fopen("student.csv","r");
    if(fr == NULL)
    {
        printf("Error opening file");
        return -1;
    }

    char a[500];
    fgets(a,200,fr);
    int count =0;

    while(fgets(a,200,fr))
    {
        count+=1;
    }

    fclose(fr);
    return count;
}