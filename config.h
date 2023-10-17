#ifndef config
#define config

#define landingPage "--------------------Welcome to Academia--------------------\nLogin Type: Enter Your Choice\n1. Admin\n2. Faculty\n3. Student\n"
#define adminMenu "You are now in ADMIN mode\nEnter your choice\n1. Add Student\n2. View Student Details\n3. Add Faculty\n4. View Faculty Details\n5. Activate Student\n6. Block Student\n7. Modify Student Details\n8. Modify Faculty Details\n9. Logout and Exit\n"

#define USERNAME "admin"
#define PASSWORD "password"

#define STUDENT_FILE "student.txt"
#define FACULTY_FILE "faculty.txt"

#define FILE_NOT_OPENED_ERROR "!!! File is not opened !!!"
#define FILE_NOT_WRITE_ERROR "!!! Data cannot be written to file !!!"
#define FILE_NOT_READ_ERROR "!!! Data cannot be read from file !!!"
#define FILE_LSEEK_ERROR "!!! Lseek error !!!+"

#define ENTER_CORRECT_CHOICE "Enter Correct Choice"

#define USER_FOUND_PROMPT "Congratulations!!! User Found"
#define USER_ACTIVATED "Congratulations!!! User is activated"
#define USER_ALREADY_ACTIVATED "!!! User is already activated !!!"
#define USER_DEACTIVATED "Congratulations!!! User is deactivated"
#define USER_ALREADY_DEACTIVATED "!!! User is already deactivated !!!"

#define MODIFY_PANEL "What do you wish to modify?\n1. Roll No\n2. Name\n3. Login Id\n4. Gender\n"
#define MODIFY_ROLLNO_PROMPT "Enter the new Roll No: \n"
#define MODIFY_NAME_PROMPT "Enter the new Name: \n"
#define MODIFY_LOGIN "Enter the new Login Id: \n"
#define MODIFY_GENDER "Enter the new Gender: \n"
#define MODIFY_CONTINUE "Do you wish to continue modification?\n1. Yes\n2. No\n"
#define MODIFY_DONE "Congratulations!!! Modification done"

#endif
