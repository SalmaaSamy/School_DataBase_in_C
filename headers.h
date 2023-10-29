#ifndef HEADERS_H
#define HEADERS_H

#include"cmd_Handler.h"
extern FILE* file_write, *file_read;
extern u32 availablePlaces[MAX_NUM_OF_STUDENTS];
void app();
void askForOperation();
void choiseForOpration();
void addStudent();
void string_scan(char*str,u32 maxSize);
int isNameValid(const char *name);
int enterPersonInfo(person_t * person);
void saveDataInFile();
void editChoise();
int string_compare(char*s1,char*s2);
void editStudentData();
void printStudentData();
void printAllStudentData();
int removeStudent();
void callStudent();
#endif // HEADERS
