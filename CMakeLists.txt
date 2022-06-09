cmake_minimum_required(VERSION 3.21)
project(Exam_Managment_System___C_Lab_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Exam_Managment_System___C_Lab_Project
        main.c
        main.h execute.c execute.h add.c add.h print_student.c print_student.h eligiblestudents.c eligiblestudents.h delete.c delete.h definition.h draft.c)
