/*#include "definition.h"
#include "delete.h"

void delete (struct student s[])
{
    int a = 0;
    printf("Enter srn of student to delete ");
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
            printf("Student Record deleted");
        }
    }
}*/