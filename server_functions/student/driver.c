#include "student_functions.h"
#include "../../records/student.h"

void main()
{
   
    // struct Student s;
    // memset(&s, 0, sizeof(s));
    // strcpy(s.loginId, "dutta.navneet17@gmail.com");
    // strcpy(s.name, "Navneet Dutta");
    // strcpy(s.password, "12345");
    // strcpy(s.rollNo, "MT2023194");
    // s.isActive = 1;
    // s.gender = 'M';
    // printf("%s  %s  %s  %c  %s  %d\n", s.rollNo, s.name, s.loginId, s.gender, s.password, s.isActive);
    // addStudent(s);

    int x = viewAllStudents();

    int y = modifyStudent("MT2023194");
}