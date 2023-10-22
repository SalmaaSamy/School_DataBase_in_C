#include "headers.h"
u32 availablePlaces[MAX_NUM_OF_STUDENTS]= {0};
school_t newStudent;
FILE* file_write, *file_read;
void app()
{
    cmdClearScreen();
    askForOperation();
}

void askForOperation()
{
    static int lastNum =1;
    u32 operationNumber=0 ;
    u8 exitFlag=0,addflag=0, removeFlag=0 ;
    file_write = fopen("school_database.txt", "a+");
    file_read = fopen("school_database.txt", "r");
    cmdSetConsoleColour(TEXT_Blue);
    choiseForOpration();
    scanf("%d",&operationNumber);
    switch(operationNumber)
    {
    case 1:
    {
        if (file_write == NULL)
        {
            printf("Error opening the file_write.\n");
            return;
        }
        file_write = fopen("school_database.txt", "a+");
        newStudent.noOfStudents=lastNum;
        /*
        if(lastNum==1)
        {
            newStudent.school = (student_t*) calloc(1000, sizeof(student_t));
            //newStudent.school = (student_t*) calloc(newStudent.noOfStudents, sizeof(student_t));
        }
        else
        {
            newStudent.school= (student_t*)realloc(newStudent.school, newStudent.noOfStudents);
        }
        */
        while(exitFlag != 'y' )
        {
            addflag= addStudent(file_write, &newStudent);
            //printf("%d\n",addflag);
            lastNum=newStudent.noOfStudents;
            if(lastNum==0)
            {
                lastNum=1;
            }
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
            fflush(stdin);
        }
        fclose(file_write);
        break;
    }
    case 2:
    {

        file_read = fopen("school_database.txt", "r");
        if (file_read == NULL)
        {
            printf("Error opening the file_read.\n");
            return;
        }
        while(exitFlag != 'y' )
        {
            editStudentData(file_read, &newStudent);
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        fclose(file_read);
        break;
    }
    case 3:
    {
        file_read = fopen("school_database.txt", "r");
        if (file_read == NULL)
        {
            printf("Error opening the file_read.\n");
            return;
        }
        while(exitFlag != 'y' )
        {
            printStudentData(file_read, &newStudent);
            printf("\t\t\t Do you want to exit  ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        fclose(file_read);
        break;
    }
    case 4:
    {
        file_read = fopen("school_database.txt", "r");
        if (file_read == NULL)
        {
            printf("Error opening the file_read.\n");
            return;
        }
        while(exitFlag != 'y' )
        {
            printAllStudentData(file_read, &newStudent);
            printf("\t\t\t Do you want to exit  ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        fclose(file_read);
        break;
    }
    case 5:
    {
        file_read = fopen("school_database.txt", "r");
        if (file_read == NULL)
        {
            printf("Error opening the file_read.\n");
            return;
        }
        while(exitFlag != 'y' )
        {
            removeFlag=removeStudent(file_read, &newStudent);
            if(removeFlag)
            {
                lastNum--;
            }
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        fclose(file_read);
        break;
    }
    case 6:
    {
        file_read = fopen("school_database.txt", "r");
        if (file_read == NULL)
        {
            printf("Error opening the file_read.\n");
            return;
        }
        while(exitFlag != 'y' )
        {
            callStudent(file_read, &newStudent);
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        fclose(file_read);
        break;
    }
    }

}
char addStudent(FILE* file_write,  school_t* newStudent)
{
    u8 enterFlag=1, flag;
    cmdClearScreen();
    if(newStudent->noOfStudents <= MAX_NUM_OF_STUDENTS)
    {
        if(newStudent->school != null_pointer)
        {
            cmdSetConsoleColour(TEXT_LPurple);
            printf("\n\n\n\t\t\t 1. Enter student name :  ");
            string_scan(newStudent->school[newStudent->noOfStudents-1].name, MAX_NUM_OF_STUDENT_NAME);
            if(isNameValid(newStudent->school[ newStudent->noOfStudents-1].name))
            {
                printf("\n\t\t\t 2. Enter student age :  ");
                scanf("%d",&newStudent->school[ newStudent->noOfStudents-1].age);
                printf("\n\t\t\t 3. Enter Student Phone  :  ");
                string_scan(newStudent->school[ newStudent->noOfStudents-1].phone, MAX_NUM_OF_PHONE);
                printf("\n\t\t\t 4. Enter student grade :  ");
                fflush(stdin);

                scanf("%c",&newStudent->school[ newStudent->noOfStudents-1].grade);
                printf("\n\t\t\t 5. Enter Father Info :  ");
                flag =enterPersonInfo(&newStudent->school[ newStudent->noOfStudents-1].father);
                if(flag)
                {
                    printf("\n\t\t\t 6. Enter Mother Info :  ");
                    flag =enterPersonInfo(&newStudent->school[ newStudent->noOfStudents-1].mother);
                    if(flag)
                    {
                        printf("\n\t\t\t 7. Enter Number of brothers :  ");
                        flag=scanf("%d",&newStudent->school[newStudent->noOfStudents-1].noOFBrothers);
                        if( flag && newStudent->school[newStudent->noOfStudents-1].noOFBrothers > 0)
                        {
                            newStudent->school[newStudent->noOfStudents-1].brothers=(person_t *)calloc(newStudent->school[newStudent->noOfStudents-1].noOFBrothers, sizeof(person_t));
                            if(newStudent->school[newStudent->noOfStudents-1].brothers !=null_pointer)
                            {
                                int i =0;
                                while((newStudent->school[ newStudent->noOfStudents-1].noOFBrothers)-- >0)
                                {
                                    printf("\t\t\t %d. Enter brother %d :  ", 8+i, i+1 );
                                    flag =enterPersonInfo(&newStudent->school[newStudent->noOfStudents-1].brothers[i++]);
                                    if(flag ==0)
                                    {
                                        enterFlag=0;
                                        availablePlaces[newStudent->school[ newStudent->noOfStudents-1].ID-1]=0;
                                        cmdSetConsoleColour(TEXT_Red);
                                        printf("\n\n\t\t\t Name is invalid !!!\n");
                                        cmdSetConsoleColour(TEXT_LPurple);
                                    }
                                }
                                if(enterFlag)
                                {
                                    cmdSetConsoleColour(TEXT_Green);
                                    printf("\n\t\t\t Adding is done successfully !!\n");
                                    cmdSetConsoleColour(TEXT_LPurple);
                                    for(int i=0 ; i<MAX_NUM_OF_STUDENTS ; i++)
                                    {
                                        if(availablePlaces[i] ==0)
                                        {
                                            newStudent->school[newStudent->noOfStudents-1].ID=i+1;
                                            availablePlaces[i]=1;
                                            printf("\n\t\t\t\t\t Your ID is :  %d\n",newStudent->school[newStudent->noOfStudents-1].ID);
                                            saveDataInFile(file_write, &newStudent->school[ newStudent->noOfStudents-1]);
                                            newStudent->noOfStudents++;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    return 0;
                                }
                            }
                        }
                        else if (flag&&newStudent->school[ newStudent->noOfStudents-1].noOFBrothers ==0)
                        {
                            cmdSetConsoleColour(TEXT_Green);
                            printf("\n\t\t\t Adding is done successfully !!\n");
                            for(int i=0 ; i<MAX_NUM_OF_STUDENTS ; i++)
                            {
                                if(availablePlaces[i] ==0)
                                {
                                    newStudent->school[ newStudent->noOfStudents-1 ].ID=i+1;
                                    availablePlaces[i]=1;
                                    printf("\n\t\t\t\t\t Your ID is :  %d\n",newStudent->school[ newStudent->noOfStudents-1].ID);
                                    saveDataInFile(file_write, &newStudent->school[ newStudent->noOfStudents-1]);
                                    newStudent->noOfStudents++;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            return 0;
                        }

                    }
                    else
                    {
                        cmdSetConsoleColour(TEXT_Red);
                        printf("\n\n\t\t\t Name is invalid !!!\n");
                        cmdSetConsoleColour(TEXT_LPurple);
                        return 0;
                    }
                }
                else
                {
                    cmdSetConsoleColour(TEXT_Red);
                    printf("\n\n\t\t\t Name is invalid !!!\n");
                    cmdSetConsoleColour(TEXT_LPurple);
                    return 0;
                }
            }
            else
            {
                cmdSetConsoleColour(TEXT_Red);
                printf("\n\n\t\t\t Name is invalid !!!\n");
                cmdSetConsoleColour(TEXT_LPurple);
                return 0;
            }
        }
        else
        {
            cmdSetConsoleColour(TEXT_Red);
            availablePlaces[newStudent->school[ newStudent->noOfStudents-1].ID-1]=0;
            printf("\n\n\n\t\t\t Sorry the school has no places !!! ");
            cmdSetConsoleColour(TEXT_LPurple);
            return 0;
        }
    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\n\t\t\t Sorry the school has no places !!! ");
        cmdSetConsoleColour(TEXT_LPurple);
        return 0;
    }
    return 1;
}
void callStudent(FILE* file_read,  school_t* newStudent)
{
    u32 userID=-1, i, index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent->noOfStudents-1 ; i++)
    {
        if(newStudent->school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent->school[index].name,userName);
    if(flag==0)
    {
        cmdSetConsoleColour(TEXT_Green);
        printf("\n\n\n\t\t\t\t");
        for(i=0; i<30; i++)
        {
            cmdSetConsoleColour(TEXT_Green);
            printf("%c",221);
            if(i==10|| i==20)
            {
                cmdSetConsoleColour(TEXT_Sky);
                system("cls");
                printf("\n\n\n\t\t\t 1. Enter student ID :  %d\n",userID);
                printf("\t\t\t 2. Enter student name :  %s\n",newStudent->school[userID-1].name);
                printf("\n\n\n\t\t\t\t");
            }
            cmdDelay(1000);
        }
        printf("\n");
    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\t\t\t You set incorrect data !!!\n");
    }
}
int removeStudent(FILE* file_read,  school_t* newStudent)
{
    u32 userID=-1, i, index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent->noOfStudents-1 ; i++)
    {
        if(newStudent->school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent->school[index].name,userName);
    if(flag==0)
    {
        newStudent->noOfStudents--;
        for(i=userID-1; i<newStudent->noOfStudents-1; i++)
        {
            newStudent->school[i]=newStudent->school[i+1];
        }

        availablePlaces[userID-1]=0;
        printf("\n\t\t\t Deleting is done successfully !!\n");
        return 1;
    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\t\t\t You set incorrect data !!!\n");
        return 0;
    }
}
void printAllStudentData(FILE* file_read,  school_t* newStudent)
{
    u32 i;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Green);
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t| ID   | Name                   |            Phone       |    Age    |     Grade       |\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<newStudent->noOfStudents -1 ; i++)
    {
        printf("\t\t|%3d   |  %-20s  |        %-11s     |    %-3d    |        %c        |\n", newStudent->school[i].ID,newStudent->school[i].name,newStudent->school[i].phone,newStudent->school[i].age, newStudent->school[i].grade);
        printf("------------------------------------------------------------------------------------------------------------------\n");
    }
}
void printStudentData(FILE* file_read,  school_t* newStudent)
{
    u32 userID=-1,i=0,index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent->noOfStudents-1 ; i++)
    {
        if(newStudent->school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent->school[index].name,userName);
    if(flag==0)
    {
        printf("------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t| Name                   |            Phone       |    Age    |     Grade       |\n");
        printf("------------------------------------------------------------------------------------------------------------------\n");

        printf("\t\t|  %-20s  |        %-11s     |    %-3d    |        %c        |\n",newStudent->school[userID-1].name,newStudent->school[userID-1].phone,newStudent->school[userID-1].age, newStudent->school[userID-1].grade);
        printf("------------------------------------------------------------------------------------------------------------------\n");

    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\t\t\t You set incorrect data !!!\n");

    }
}
void editStudentData(FILE* file_read,  school_t* newStudent)
{
    u32 userID=-1, i,operation=0,index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2, exitFlag=0;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent->noOfStudents-1 ; i++)
    {
        if(newStudent->school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent->school[index].name,userName);
    if(flag==0)
    {
        while(exitFlag != 'y' )
        {
            cmdClearScreen();
            editChoise();
            flag=scanf("%d",&operation);
            if(flag)
            {
                switch(operation)
                {
                case 1:
                    printf("\n\t\t\t\t  Enter name :  ");
                    string_scan(newStudent->school[userID-1].name, MAX_NUM_OF_STUDENT_NAME);
                    break;
                case 2:
                    printf("\n\t\t\t\t  Enter phone:  ");
                    string_scan(newStudent->school[userID-1].phone, MAX_NUM_OF_PHONE);
                    break;
                case 3:
                    printf("\n\t\t\t\t Enter age :  ");
                    scanf("%d",&newStudent->school[userID-1].age);
                    break;
                case 4:
                    fflush(stdin);
                    printf("\n\t\t\t\t  Enter Grade :  ");
                    scanf("%c",&newStudent->school[userID-1].grade);
                    break;
                default:
                    printf("\t\t\tInvalid Operation\n");
                }

            }
            else
            {
                printf("\t\t\tInvalid Operation\n");
            }
            printf("\t\t\t Do you want to exit edit ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\t\t\t You set incorrect data !!!\n");

    }
}
void saveDataInFile(FILE* file_write, student_t *studentData)
{
    fprintf(file_write, "ID: %d\n",studentData->ID);
    fprintf(file_write,"Name: %s\n",studentData->name);
    fprintf(file_write,"Age: %d\n", studentData->age);
    fprintf(file_write,"Phone: %s\n",studentData->phone);
    fprintf(file_write,"Grade: %c\n",studentData->grade);
    fprintf(file_write, "\n");
}
int enterPersonInfo(person_t * person)
{
    printf("\n\t\t\t\t 1. Enter name :  ");
    string_scan(person->name, MAX_NUM_OF_PERSON_NAME);
    if(isNameValid(person->name))
    {
        printf("\t\t\t\t 2. Enter age :  ");
        scanf("%d",&person->age);
        printf("\t\t\t\t 3. Enter Phone  :  ");
        string_scan(person->phone, MAX_NUM_OF_PHONE);
        return 1;
    }
    return 0;

}
void string_scan(char *str,u32 maxSize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for(; str[i]!='\n';)
    {
        i++;
        scanf("%c",&str[i]);
        if(i==maxSize-1)
        {
            break;
        }
    }
    str[i]=0;
}
int isNameValid(const char *name)
{
    while (*name)
    {
        if (!isalpha(*name))
            return 0;
        name++;
    }
    return 1;
}
void editChoise()
{
    cmdSetConsoleColour(TEXT_LYellow);
    printf("\t\t   Enter number for operation you want to edit \n");
    cmdSetConsoleColour(TEXT_Blue);
    printf("\t\t\t 1. Name \n");
    printf("\t\t\t 2. Phone \n");
    printf("\t\t\t 3. age \n");
    printf("\t\t\t 4. Grade \n");
}
void choiseForOpration()
{
    printf("\n\n\n\t\t---------- Welcome to Our School ^-^ ---------- \n");
    cmdSetConsoleColour(TEXT_LYellow);
    printf("\t\t   Enter number for operation you want\n");
    cmdSetConsoleColour(TEXT_Blue);
    printf("\t\t\t 1. Add new student\n");
    printf("\t\t\t 2. Edit current student\n"); // by name or id ==> edit name , phone , age , grade
    printf("\t\t\t 3. Print student\n"); // by name or id
    printf("\t\t\t 4. Print all student\n");
    printf("\t\t\t 5. Delete student\n"); // by name or id
    printf("\t\t\t 6. Call student\n"); // by name or id
}
int string_compare(char*s1,char*s2)
{
    int i;
    for(i=0; s2[i]||s1[i]; i++)
    {
        if(s1[i]>s2[i])
        {
            return 1;
        }
        else if(s1[i]<s2[i])
        {
            return -1;
        }
    }
    return 0;
}

