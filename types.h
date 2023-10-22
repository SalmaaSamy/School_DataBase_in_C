#ifndef TYPES_H
#define TYPES_H

#define MAX_NUM_OF_STUDENTS 1000
#define MAX_NUM_OF_STUDENT_NAME 21
#define MAX_NUM_OF_PERSON_NAME 21
#define MAX_NUM_OF_PHONE 12
#define null_pointer ((void*)0)
typedef char u8;
typedef int u32;
typedef short u16;
typedef struct
{
    u32 age;
    u8 name[21];
    u8 phone[12];
} person_t;

typedef struct
{
    person_t father;
    person_t mother;
    person_t* brothers;
    u32 age;
    u32 noOFBrothers;
    u32 ID;
    u8 name[21];
    u8 grade;
    u8 phone[12];
} student_t;
typedef struct
{
    student_t *school;
    int noOfStudents;
} school_t;
extern school_t newStudent;
#endif // TYPES
