#include "result.h"

void calculateTotalAndPercentage(Student *s){
    s->total = 0;
    for (int i = 0; i < SUBJECTS; i++){
        s->total_marks[i] = s->minor_marks[i] + s->major_marks[i];
        s->total += s->total_marks[i];
    }
    s->percentage = s->total /5.0;
}


char assignGrade(float percentage){
    if (percentage >= 90) return 'O';
    if (percentage >= 85) return '+';
    if (percentage >= 75) return 'A';
    if (percentage >= 65) return 'B';
    if (percentage >= 60) return 'C';
    if (percentage >= 55) return 'D';
    if (percentage >= 50) return 'E';
    return 'F';
}


void calculateCGPA(Student *s){
    if (s->percentage >= 90) s->cgpa = 10.0;
    else if(s->percentage >= 85) s->cgpa = 9.0;
    else if(s->percentage >= 75) s->cgpa = 8.0;
    else if(s->percentage >= 65) s->cgpa = 7.0;
    else if(s->percentage >= 60) s->cgpa = 6.0;
    else if(s->percentage >= 55) s->cgpa = 5.0;
    else if(s->percentage >= 50) s->cgpa = 4.0;
    else s->cgpa = 0.0;
}

int isValidSubjectPass(const Student *s){
    for(int i = 0; i < SUBJECTS; i++){
        float subject_total = s->minor_marks[i] + s->major_marks[i];
        float subject_percentage = (subject_total / 100) * 100;
        if (subject_percentage < MIN_PASSING_MARKS){
            return 0;
        }
    }

    return 1;
}