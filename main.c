#include <stdio.h>
#include "student.h"
#include "fileio.h"

int main(){
    StudentDatabase db = { .count = 0};

    if (readStudentsFromFile("students.txt", &db) == 0){
        printf("No valid student records found.\n");
        return 1;
    }

    writeReportToFile("Student_Result_Report.txt", &db);

    printf("Processing complete.\n");
    return 0;
}