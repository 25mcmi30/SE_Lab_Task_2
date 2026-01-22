#include "stats.h"

float calculateClassAverage(StudentDatabase *db){
    if (db->count == 0) return 0;
    float sum = 0;
    for (int i = 0; i < db->count; i++){
        sum += db->students[i].percentage;
    }
    return sum / db->count;
}
void findHighestLowest(StudentDatabase *db, float *highest, float *lowest){
    if (db->count == 0){
        *highest = 0;
        *lowest = 0;
        return;
    }

    *highest = db->students[0].percentage;
    *lowest = db->students[0].percentage;

    for (int i = 1; i < db->count; i++){
        if (db->students[i].percentage > *highest){
            *highest = db->students[i].percentage;
        }

        if (db->students[i].percentage < *lowest){
            *lowest = db->students[i].percentage;
        }
    }
}
void countGrades(StudentDatabase *db, int *grade_count){
    for (int i = 0; i< 7; i++) grade_count[i] = 0;

    for (int i = 0; i < db->count; i++){
        if (db->students[i].percentage>=90) grade_count[0]++;
        else if (db->students[i].percentage >= 85) grade_count[1]++;
        else if (db->students[i].percentage >= 75) grade_count[2]++;
        else if (db->students[i].percentage >= 65) grade_count[3]++;
        else if (db->students[i].percentage >= 60) grade_count[4]++;
        else if (db->students[i].percentage >= 55) grade_count[5]++;
        else if (db->students[i].percentage >= 50) grade_count[6]++;
        else grade_count[7]++;
    }
}