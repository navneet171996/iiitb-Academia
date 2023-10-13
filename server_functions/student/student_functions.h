/*
    Author @Nabaneet_MT2023194
*/
#ifndef student_functions
#define student_functions

#include "../common.h"
#include "../../config.h"
#include "../../records/student.h"

int addStudent(struct Student stud) 
{
    int studentFD = open(STUDENT_FILE, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if(studentFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }
    ssize_t writeBytes = write(studentFD, &stud, sizeof(stud));
    if(writeBytes == -1){
        perror(FILE_NOT_WRITE_ERROR);
        return -1;
    }

    close(studentFD);
    return 1;
}

int viewAllStudents()
{
    struct Student stud;
    int studentFD = open(STUDENT_FILE, O_RDONLY, S_IRUSR);
    if(studentFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }
    ssize_t readBytes;
    while(readBytes = read(studentFD, &stud, sizeof(struct Student))>0)
    {
        printf("%s  %s  %s  %c  %s  %d\n", stud.rollNo, stud.name, stud.loginId, stud.gender, stud.password, stud.isActive);
    }
    if(readBytes == -1)
    {
        perror(FILE_NOT_READ_ERROR);
        return -1;
    }

    close(studentFD);
    return 1;
    
}

int modifyStudent(char rollNo[])
{
    struct Student stud;
    int studentFD = open(STUDENT_FILE, O_RDONLY | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
    if(studentFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }
    ssize_t readBytes;

    while(readBytes = read(studentFD, &stud, sizeof(struct Student))>0)
    {
        // fjasoidjf
        if(strcmp(stud.rollNo, rollNo)==0)
        {
            printf(USER_FOUND_PROMPT);
            while(1)
            {
                printf(MODIFY_PANEL);
                int choice;
                scanf("%d", &choice);
                switch (choice)
                {
                    case 1:
                        printf(MODIFY_ROLLNO_PROMPT);
                        char newRollNo[10];
                        scanf("%s", newRollNo);
                        strcpy(stud.rollNo, newRollNo);
                        break;
                    
                    case 2:
                        printf(MODIFY_NAME_PROMPT);
                        char newName[30];
                        scanf("%s", newName);
                        strcpy(stud.name, newName);
                        break;
                    
                    case 3:
                        printf(MODIFY_LOGIN);
                        char newLoginId[30];
                        scanf("%s", newLoginId);
                        strcpy(stud.loginId, newLoginId);
                        break;
                    
                    case 4:
                        printf(MODIFY_GENDER);
                        char newGender;
                        scanf("%s", &newGender);
                        stud.gender = newGender;
                        break;
                    
                    default:
                        printf(ENTER_CORRECT_CHOICE);
                        break;
                }
                printf(MODIFY_CONTINUE);
                int choice2;
                scanf("%d", &choice2);
                if(choice2 == 2)
                    break;
            }
            ssize_t writeBytes;
            writeBytes = write(studentFD, &stud, sizeof(stud));
            if(writeBytes == -1)
            {
                perror(FILE_NOT_WRITE_ERROR);
                return -1;
            }

        break;   
        }
    }
    if(readBytes == -1)
    {
        perror(FILE_NOT_READ_ERROR);
        return -1;
    }
    printf(MODIFY_DONE);
}
#endif