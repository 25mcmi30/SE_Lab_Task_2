#include "fileio.h"

int readStudentsFromFile(const char *filename, StudentDatabase *db){
    FILE *fp = fopen(filename, "r");
    if (!fp){
        fprintf(stderr, "Error: Cannot open file%s\n", filename);
        return 0;
    }

    char line[512];
    db->count = 0;

    while(fgets(line, sizeof(line), fp) && db->count < MAX_STUDENTS){
        char id[MAX_ID_LEN], name[MAX_NAME_LEN];
        float m[10];

        if(sscanf(line, "%s %s %f %f %f %f %f %f %f %f %f %f", id, name, &m[0], &m[1], &m[2], &m[3], &m[4], &m[5], &m[6], &m[7], &m[8], &m[9]) != 12){
            fprintf(stderr, "Warning: Invalid format in line\n");
            continue;
        }

        if (!isValidID(id, db)){
            fprintf(stderr, "Warning: Invalid or duplicate ID %s\n", id);
            continue;
        }

        if (!isValidName(name)){
            fprintf(stderr, "Warning: Invalid name %s\n", name);
            continue;
        }

        int valid = 1;
        for (int i = 0; i < 10; i++){
            if (!isValidMarks(m[i])){
                fprintf(stderr, "Warning: Invalid marks for student %s\n", id);
                valid = 0;
                break;
            }
        }
        if (!valid) continue;

        strcpy(db->students[db->count].id, id);
        strcpy(db->students[db->count].name, name);

        for (int i = 0; i < SUBJECTS; i++){
            db->students[db->count].minor_marks[i] = m[i*2];
            db->students[db->count].major_marks[i] = m[i*2 + 1];
        }

        calculateTotalAndPercentage(&db->students[db->count]);
        db->students[db->count].grade = assignGrade(db->students[db->count].percentage);
        calculateCGPA(&db->students[db->count]);

        db->count++;
    }

    fclose(fp);
    return db->count;
}

void writeReportToFile(const char *filename, StudentDatabase *db){
    FILE *fp = fopen(filename, "w");
    if (!fp){
        fprintf(stderr, "Error: Cannot create output file %s\n", filename);
        return;
    }

    fprintf(fp, "------------------------------------------\n");
    fprintf(fp, "STUDENT RESULT REPORT\n");
    fprintf(fp, "------------------------------------------\n\n");

    fprintf(fp, "%-15s %-15s ", "Student ID", "Name");
    for(int i = 0; i < SUBJECTS; i++){
        fprintf(fp, " S%d-Minor    S%d-Major ", i+1, i+1);
    }
    fprintf(fp, "%-8s %-10s %-7s %-6s\n", "   Total", "  Percent", " Grade", "   CGPA");

    fprintf(fp, "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < db->count; i++){
        fprintf(fp, "%-15s %-20s ", db->students[i].id, db->students[i].name);

        for(int j = 0; j < SUBJECTS; j++){
            fprintf(fp, "%-10.0f %-10.0f ", db->students[i].minor_marks[j], db->students[i].major_marks[j]);
        }

        fprintf(fp, "%-6.0f %-10.2f %-7c %-6.2f\n",
            db->students[i].total,
            db->students[i].percentage,
            db->students[i].grade,
            db->students[i].cgpa);
    }

    fprintf(fp, "\n\n--------------\n");
    fprintf(fp, "STATISTICS\n");
    fprintf(fp, "--------------\n\n");

    float class_avg = calculateClassAverage(db);
    float highest, lowest;
    findHighestLowest(db, &highest, &lowest);
    int grade_count[8] = {0};
    countGrades(db, grade_count);

    fprintf(fp, "Total Students: %d\n", db->count);
    fprintf(fp, "Class Average Percentage: %.2f%%\n", class_avg);
    fprintf(fp, "Highest Percentage: %.2f%%\n", highest);
    fprintf(fp, "Lowest Percentage: %.2f%%\n\n", lowest);

    fprintf(fp, "Grade Distribution: \n");
    fprintf(fp, " O  (>= 90): %d students\n", grade_count[0]);
    fprintf(fp, " A+ (85-90): %d students\n", grade_count[1]);
    fprintf(fp, " A  (75-85): %d students\n", grade_count[2]);
    fprintf(fp, " B+ (65-75): %d students\n", grade_count[3]);
    fprintf(fp, " B  (60-65): %d students\n", grade_count[4]);
    fprintf(fp, " C  (55-60): %d students\n", grade_count[5]);
    fprintf(fp, " D  (50-55): %d students\n", grade_count[6]);
    fprintf(fp, " F  (< 50 ): %d students\n", grade_count[7]);

    fprintf(fp, "\n------------------------------------------\n");

    fclose(fp);

    printf("Report successfully written to %s\n", filename);
}