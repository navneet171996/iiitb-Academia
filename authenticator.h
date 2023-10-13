#ifndef authenticator
#define authenticator

#include "config.h"
#include <string.h>

int authenticateAdmin(char* username, char* password)
{
    if((strcmp(username, USERNAME) && strcmp(password, PASSWORD))==0){
        return 1;
    }
    return 0;
}

//Mode: 1-Admin 2-Faculty 3-Student

int authenticate(char* username, char* password, int mode)
{
    if(mode == 1)
        authenticateAdmin(username, password);
}

#endif