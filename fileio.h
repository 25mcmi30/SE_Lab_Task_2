#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"
#include "validation.h"
#include "result.h"
#include "stats.h"

int readStudentsFromFile(const char *filename, StudentDatabase *db);
void writeReportToFile(const char *filename, StudentDatabase *db);

#endif