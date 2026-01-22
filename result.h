#ifndef RESULT_H
#define RESULT_H

#include "student.h"

#define MIN_PASSING_MARKS 50

void calculateTotalAndPercentage(Student *s);
char assignGrade(float percentage);
void calculateCGPA(Student *s);
int isValidSubjectPass(const Student *s);

#endif