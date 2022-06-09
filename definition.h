#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int option = 0;
int i = 0;
int n = 0;
int j = 0;
float present = 75.00;
char fee = 'P';
float tdays = 1;

struct student {
    char name[20];
    int rno;
    char fees;
    float days;
    float attend;
} s[50];