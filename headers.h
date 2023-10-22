#ifndef HEADERS_H
#define HEADERS_H

#include"cmd_Handler.h"

void app();
void askForOperation();
void choiseForOpration();
char addStudent(FILE* file_write , school_t* newStudent);
void string_scan(char*str,u32 maxSize);
int isNameValid(const char *name);
int enterPersonInfo(person_t * person);
void saveDataInFile(FILE* file , student_t* studentData);
void editChoise();
int string_compare(char*s1,char*s2);
void editStudentData(FILE* file_read,  school_t* newStudent);
void printStudentData(FILE* file_read,  school_t* newStudent);
void printAllStudentData(FILE* file_read,  school_t* newStudent);
int removeStudent(FILE* file_read,  school_t* newStudent);
void callStudent(FILE* file_read,  school_t* newStudent);
#endif // HEADERS
