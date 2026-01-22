#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20
#define SUBJECTS 5

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    float minor_marks[SUBJECTS];
    float major_marks[SUBJECTS];
    float total_marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
    float cgpa;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} StudentDatabase;

#endif