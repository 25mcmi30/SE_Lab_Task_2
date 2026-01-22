#include "validation.h"

int isValidID(const char *id, StudentDatabase *db){
    if (!isAlphaNumeric(id)) return 0;

    for (int i = 0; i< db->count; i++){
        if (strcmp(db->students[i].id, id) == 0) return 0;
    }

    return 1;
}


int isValidName(const char *name){
    return isOnlyAlpha(name);
}

int isValidMarks(float mark){
    return (mark >=0 && mark <= 100);
}

int isAlphaNumeric(const char *str){
    if (!str || strlen(str) == 0) return 0;
    for (int i = 0; str[i]; i++){
        if (!isalnum(str[i])) return 0;
    }
    return 1;
}

int isOnlyAlpha(const char *str){
    if (!str || strlen(str) == 0) return 0;
    for (int i = 0; str[i]; i++){
        if (!isalpha(str[i]) && str[i] != ' ') return 0;
    }
    return 1;
}