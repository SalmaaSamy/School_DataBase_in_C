#include "headers.h"
int main()
{
    int i = 0, k=0, x=0;
    newStudent.school = (student_t*) calloc(1000, sizeof(student_t));
    newStudent.noOfStudents=0;
    file_read=fopen("school_database.txt","r");
    if (file_read == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }
    fscanf(file_read,"%d",&newStudent.noOfStudents);
    newStudent.noOfStudents++;
    for (i = 0; i <=newStudent.noOfStudents; i++)
    {
        fscanf(file_read, "%d %s %d %s %c",&newStudent.school[i].ID,newStudent.school[i].name,&newStudent.school[i].age,newStudent.school[i].phone,&newStudent.school[i].grade);
    }
    fclose(file_read);

    for(i = 0; i <newStudent.noOfStudents; i++)
    {
        for(k=1; k<MAX_NUM_OF_STUDENTS; k++)
        {
            if(newStudent.school[x].ID == k)
            {
                x++;
                availablePlaces[k-1]=1;
                break;
            }
            else{
                availablePlaces[i]=0;
            }
        }
    }
    for(i = 0; i <newStudent.noOfStudents; i++)
    {
        printf("%d\t",availablePlaces[i]);
    }
    while(1)
    {
        app();
    }
    return 0;
}
