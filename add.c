/*#include "add.h"
#include "definition.h"
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

}*/