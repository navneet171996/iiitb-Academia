/*
    Author @Nabaneet_MT2023194
*/
#ifndef faculty_functions
#define faculty_functions

#include "../common.h"
#include "../../config.h"

int addFaculty(struct Faculty fac)
{
    int facultyFD = open(FACULTY_FILE,  O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if(facultyFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }
    ssize_t writeBytes = write(facultyFD, &fac, sizeof(fac));
    if(writeBytes == -1){
        perror(FILE_NOT_WRITE_ERROR);
        return -1;
    }

    close(facultyFD);
    return 1;
}

int viewAllFaculty()
{
    struct Faculty fac;
    int facultyFD = open(FACULTY_FILE, O_RDONLY, S_IRUSR);
    if(facultyFD == -1)
    {
        perror(FILE_NOT_OPENED_ERROR);
        return -1;
    }
    ssize_t readBytes;
    while(readBytes = read(facultyFD, &fac, sizeof(struct Faculty))>0)
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
#endif