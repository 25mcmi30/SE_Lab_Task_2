#ifndef STATS_H
#define STATS_H

#include "student.h"

float calculateClassAverage(StudentDatabase *db);
void findHighestLowest(StudentDatabase *db, float *highest, float *lowest);
void countGrades(StudentDatabase *db, int *grade_count);

#endif