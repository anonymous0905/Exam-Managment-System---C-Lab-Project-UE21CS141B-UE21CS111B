/*#include "execute.h"
#include "add.h"
#include "print_student.h"
#include "eligiblestudents.h"
#include "delete.h"
#include "definition.h"
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
            printf("Enter fee status P/N/B");
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
}*/