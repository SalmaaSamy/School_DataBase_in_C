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
    u32 operationNumber=0 ;
    u8 exitFlag=0;
    cmdSetConsoleColour(TEXT_Blue);
    choiseForOpration();
    scanf("%d",&operationNumber);
    switch(operationNumber)
    {
    case 1:
    {
        while(exitFlag != 'y' )
        {
            addStudent();
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
            fflush(stdin);
        }
        break;
    }
    case 2:
    {
        while(exitFlag != 'y' )
        {
            editStudentData();
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        fclose(file_read);
        break;
    }
    case 3:
    {
        while(exitFlag != 'y' )
        {
            printStudentData();
            printf("\t\t\t Do you want to exit  ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        break;
    }
    case 4:
    {
        while(exitFlag != 'y' )
        {
            printAllStudentData();
            printf("\t\t\t Do you want to exit  ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        break;
    }
    case 5:
    {
        while(exitFlag != 'y' )
        {
            removeStudent();
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        break;
    }
    case 6:
    {
        while(exitFlag != 'y' )
        {
            callStudent();
            printf("\t\t\t Do you want to exit adding ? press [y to exit and any key to continue]\n");
            fflush(stdin);
            scanf("%c",&exitFlag);
        }
        break;
    }
    }
}
void addStudent()
{
    u8 enterFlag=1, flag;
    cmdClearScreen();
    if(newStudent.noOfStudents <= MAX_NUM_OF_STUDENTS)
    {
        if(newStudent.school != null_pointer)
        {
            cmdSetConsoleColour(TEXT_LPurple);
            printf("\n\n\n\t\t\t 1. Enter student name :  ");
            string_scan(newStudent.school[newStudent.noOfStudents-1].name, MAX_NUM_OF_STUDENT_NAME);
            if(isNameValid(newStudent.school[newStudent.noOfStudents-1].name))
            {
                printf("\n\t\t\t 2. Enter student age :  ");
                scanf("%d",&newStudent.school[newStudent.noOfStudents-1].age);
                printf("\n\t\t\t 3. Enter Student Phone  :  ");
                string_scan(newStudent.school[ newStudent.noOfStudents-1].phone, MAX_NUM_OF_PHONE);
                printf("\n\t\t\t 4. Enter student grade :  ");
                fflush(stdin);

                scanf("%c",&newStudent.school[newStudent.noOfStudents-1].grade);
                printf("\n\t\t\t 5. Enter Father Info :  ");
                flag =enterPersonInfo(&newStudent.school[newStudent.noOfStudents-1].father);
                if(flag)
                {
                    printf("\n\t\t\t 6. Enter Mother Info :  ");
                    flag =enterPersonInfo(&newStudent.school[newStudent.noOfStudents-1].mother);
                    if(flag)
                    {
                        printf("\n\t\t\t 7. Enter Number of brothers :  ");
                        flag=scanf("%d",&newStudent.school[newStudent.noOfStudents-1].noOFBrothers);
                        if( flag && newStudent.school[newStudent.noOfStudents-1].noOFBrothers > 0)
                        {
                            newStudent.school[newStudent.noOfStudents-1].brothers=(person_t *)calloc(newStudent.school[newStudent.noOfStudents-1].noOFBrothers, sizeof(person_t));
                            if(newStudent.school[newStudent.noOfStudents-1].brothers !=null_pointer)
                            {
                                int i =0;
                                while((newStudent.school[newStudent.noOfStudents-1].noOFBrothers)-- >0)
                                {
                                    printf("\t\t\t %d. Enter brother %d :  ", 8+i, i+1 );
                                    flag =enterPersonInfo(&newStudent.school[newStudent.noOfStudents-1].brothers[i++]);
                                    if(flag ==0)
                                    {
                                        enterFlag=0;
                                        availablePlaces[newStudent.school[newStudent.noOfStudents-1].ID-1]=0;
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
                                            newStudent.school[newStudent.noOfStudents-1].ID=i+1;
                                            availablePlaces[i]=1;
                                            printf("\n\t\t\t\t\t Your ID is :  %d\n",newStudent.school[newStudent.noOfStudents-1].ID);
                                            saveDataInFile();
                                            newStudent.noOfStudents++;
                                            break;

                                        }
                                    }
                                }
                                else
                                {
                                    return;
                                }
                            }
                        }
                        else if (flag&&newStudent.school[newStudent.noOfStudents-1].noOFBrothers ==0)
                        {
                            cmdSetConsoleColour(TEXT_Green);
                            printf("\n\t\t\t Adding is done successfully !!\n");
                            for(int i=0 ; i<MAX_NUM_OF_STUDENTS ; i++)
                            {
                                if(availablePlaces[i] ==0)
                                {
                                    newStudent.school[newStudent.noOfStudents-1].ID=i+1;
                                    availablePlaces[i]=1;
                                    printf("\n\t\t\t\t\t Your ID is :  %d\n",newStudent.school[newStudent.noOfStudents-1].ID);
                                    saveDataInFile();
                                    newStudent.noOfStudents++;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            return;
                        }

                    }
                    else
                    {
                        cmdSetConsoleColour(TEXT_Red);
                        printf("\n\n\t\t\t Name is invalid !!!\n");
                        cmdSetConsoleColour(TEXT_LPurple);
                        return;
                    }
                }
                else
                {
                    cmdSetConsoleColour(TEXT_Red);
                    printf("\n\n\t\t\t Name is invalid !!!\n");
                    cmdSetConsoleColour(TEXT_LPurple);
                    return;
                }
            }
            else
            {
                cmdSetConsoleColour(TEXT_Red);
                printf("\n\n\t\t\t Name is invalid !!!\n");
                cmdSetConsoleColour(TEXT_LPurple);
                return;
            }
        }
        else
        {
            cmdSetConsoleColour(TEXT_Red);
            availablePlaces[newStudent.school[newStudent.noOfStudents-1].ID-1]=0;
            printf("\n\n\n\t\t\t Sorry the school has no places !!! ");
            cmdSetConsoleColour(TEXT_LPurple);
            return;
        }
    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\n\t\t\t Sorry the school has no places !!! ");
        cmdSetConsoleColour(TEXT_LPurple);
        return;
    }
}
void callStudent()
{
    u32 userID=-1, i, index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent.noOfStudents ; i++)
    {
        if(newStudent.school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent.school[index].name,userName);
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
                printf("\t\t\t 2. Enter student name :  %s\n",newStudent.school[index].name);
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
int removeStudent()
{
    u32 userID=-1, i, index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent.noOfStudents; i++)
    {
        if(newStudent.school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent.school[index].name,userName);
    if(flag==0)
    {
        newStudent.noOfStudents--;
        printf("%d",newStudent.noOfStudents);
        for(i=index; i<newStudent.noOfStudents-1; i++)
        {
            newStudent.school[i]=newStudent.school[i+1];
        }
        availablePlaces[index]=0;
        printf("\n\t\t\t Deleting is done successfully !!\n");
        newStudent.noOfStudents--;
        saveDataInFile();
        newStudent.noOfStudents++;
        return 1;
    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\t\t\t You set incorrect data !!!\n");
        return 0;
    }
}
void printAllStudentData()
{
    u32 i;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Green);
    fclose(file_read);
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t| ID   | Name                   |            Phone       |    Age    |     Grade       |\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<newStudent.noOfStudents-1; i++)
    {
        printf("\t\t|%3d   |  %-20s  |        %-11s     |    %-3d    |        %c        |\n", newStudent.school[i].ID,newStudent.school[i].name,newStudent.school[i].phone,newStudent.school[i].age, newStudent.school[i].grade);
        printf("------------------------------------------------------------------------------------------------------------------\n");
    }
}
void printStudentData()
{
    u32 userID=-1,i=0,index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent.noOfStudents; i++)
    {
        if(newStudent.school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent.school[index].name,userName);
    if(flag==0)
    {
        printf("------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t| Name                   |            Phone       |    Age    |     Grade       |\n");
        printf("------------------------------------------------------------------------------------------------------------------\n");

        printf("\t\t|  %-20s  |        %-11s     |    %-3d    |        %c        |\n",newStudent.school[index].name,newStudent.school[index].phone,newStudent.school[index].age, newStudent.school[index].grade);
        printf("------------------------------------------------------------------------------------------------------------------\n");

    }
    else
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("\n\n\t\t\t You set incorrect data !!!\n");

    }
}
void editStudentData()
{
    u32 userID=-1, i,operation=0,index=-1;
    u8 userName[MAX_NUM_OF_STUDENT_NAME], flag=-2, exitFlag=0;
    cmdClearScreen();
    cmdSetConsoleColour(TEXT_Sky);
    printf("\n\n\n\t\t\t 1. Enter student ID :  ");
    scanf("%d",&userID);
    printf("\t\t\t 2. Enter student name :  ");
    string_scan(userName, MAX_NUM_OF_STUDENT_NAME);
    for(i=0; i<newStudent.noOfStudents ; i++)
    {
        if(newStudent.school[i].ID == userID)
        {
            index=i;
            break;
        }
    }
    flag=string_compare(newStudent.school[index].name,userName);
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
                    string_scan(newStudent.school[index].name, MAX_NUM_OF_STUDENT_NAME);
                    break;
                case 2:
                    printf("\n\t\t\t\t  Enter phone:  ");
                    string_scan(newStudent.school[index].phone, MAX_NUM_OF_PHONE);
                    break;
                case 3:
                    printf("\n\t\t\t\t Enter age :  ");
                    scanf("%d",&newStudent.school[index].age);
                    break;
                case 4:
                    fflush(stdin);
                    printf("\n\t\t\t\t  Enter Grade :  ");
                    scanf("%c",&newStudent.school[index].grade);
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
    saveDataInFile();
}
void saveDataInFile()
{
    int i=0;
    file_write = fopen("school_database.txt", "w");
    fprintf(file_write,"%d\n",newStudent.noOfStudents);
    for(i=0; i<newStudent.noOfStudents; i++)
    {
        fprintf(file_write, "%d %s %d %s %c\n",newStudent.school[i].ID,newStudent.school[i].name,newStudent.school[i].age,newStudent.school[i].phone,newStudent.school[i].grade);
    }
    fclose(file_write);

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

