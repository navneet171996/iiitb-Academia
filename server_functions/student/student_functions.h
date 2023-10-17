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
    int studentFD = open(STUDENT_FILE, O_RDWR , S_IRUSR | S_IWUSR);
    if(studentFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }
    ssize_t readBytes;
    off_t offset2 = 0;
    while((readBytes = read(studentFD, &stud, sizeof(struct Student)))>0)
    {
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
                        scanf(" %c", &newGender);
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
            off_t offset = -1*sizeof(struct Student);
            if(lseek(studentFD, offset, SEEK_CUR)==-1)
            {
                perror(FILE_LSEEK_ERROR);
                return -1;
            };
            ssize_t writeBytes;
            writeBytes = write(studentFD, &stud, sizeof(stud));
            if(writeBytes == -1)
            {
                perror(FILE_NOT_WRITE_ERROR);
                return -1;
            }
            break;   
        }
        offset2 += sizeof(struct Student);
        printf("%d\n", offset2);
    }
    if(readBytes == -1)
    {
        perror(FILE_NOT_READ_ERROR);
        return -1;
    }
    printf(MODIFY_DONE);
    close(studentFD);
    return 1;
}

int activateStudent(char rollNo[])
{
    int studentFD = open(STUDENT_FILE, O_RDWR, S_IRUSR | S_IWUSR);
    if(studentFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }

    struct Student stud;
    ssize_t readBytes;
    while((readBytes = read(studentFD, &stud, sizeof(struct Student)) > 0))
    {
        if(strcmp(stud.rollNo, rollNo)==0)
        {
            if(stud.isActive == 0)
            {
                stud.isActive = 1;
                off_t offset = -1*sizeof(struct Student);
                if(lseek(studentFD, offset, SEEK_CUR)==-1)
                {
                    perror(FILE_LSEEK_ERROR);
                    return -1;
                }
                ssize_t writeBytes = write(studentFD, &stud, sizeof(struct Student));
                if(writeBytes == -1)
                {
                    perror(FILE_NOT_WRITE_ERROR);
                    return -1;
                }
                break;
            }
            else
            {
                printf(USER_ALREADY_ACTIVATED);
                return -1;
            }

        }
    }
    if(readBytes == -1)
    {
        perror(FILE_NOT_READ_ERROR);
        return -1;
    }
    printf(USER_ACTIVATED);
    return 1;
}

int deactivateStudent(char rollNo[])
{
    int studentFD = open(STUDENT_FILE, O_RDWR, S_IRUSR | S_IWUSR);
    if(studentFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }

    struct Student stud;
    ssize_t readBytes;
    while((readBytes = read(studentFD, &stud, sizeof(struct Student)) > 0))
    {
        if(strcmp(stud.rollNo, rollNo)==0)
        {
            if(stud.isActive == 1)
            {
                stud.isActive = 0;
                off_t offset = -1*sizeof(struct Student);
                if(lseek(studentFD, offset, SEEK_CUR)==-1)
                {
                    perror(FILE_LSEEK_ERROR);
                    return -1;
                }
                ssize_t writeBytes = write(studentFD, &stud, sizeof(struct Student));
                if(writeBytes == -1)
                {
                    perror(FILE_NOT_WRITE_ERROR);
                    return -1;
                }
                break;
            }
            else
            {
                printf(USER_ALREADY_DEACTIVATED);
                return -1;
            }
        }
    }
    if(readBytes == -1)
    {
        perror(FILE_NOT_READ_ERROR);
        return -1;
    }
    printf(USER_DEACTIVATED);
    close(studentFD);
    return 1;
}

#endif