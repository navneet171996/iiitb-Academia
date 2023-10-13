#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "config.h"

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Initialize server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    //Landing Page and Authentication
    int landingChoice;
    char username[100];
    char password[100];
    printf("%s", landingPage);
    scanf("%d", &landingChoice);
    switch(landingChoice){
        case 1:
            printf("Enter Username: ");
            scanf("%s", username);
            printf("Enter Password: ");
            scanf("%s", password);
            send(client_socket, username, sizeof(username), 0);
            send(client_socket, password, sizeof(password), 0);
            break;

    }
   
    char response[100];
    recv(client_socket, response, sizeof(response), 0);
    printf("Server response: %s\n", response);

    if (strcmp(response, "Authentication successful") == 0) {
        char adminPanel[1000];
        int choice;
        bzero(adminPanel, sizeof(adminPanel));
        recv(client_socket, adminPanel, sizeof(adminPanel),0);
        while(1)
        {
            char res[100];
            printf("%s", adminPanel);
            scanf("%d", &choice);
            send(client_socket, &choice, sizeof(int), 0);
            recv(client_socket, res, sizeof(response), 0);
            printf("%s", res);
            if(choice == 9)
                break;
        }
    }

    // Cleanup
    close(client_socket);

    return 0;
}

