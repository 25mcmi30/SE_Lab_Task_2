#ifndef VALIDATION_H
#define VALIDATION_H

#include "student.h"

int isValidID(const char *id, StudentDatabase *db);
int isValidName(const char *name);
int isValidMarks(float mark);
int isAlphaNumeric(const char *str);
int isOnlyAlpha(const char *str);

#endif