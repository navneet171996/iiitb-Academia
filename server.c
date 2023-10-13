#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define USERNAME "admin"
#define PASSWORD "password"

#include "config.h"
#include "authenticator.h"

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Initialize server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr =inet_addr("127.0.0.1");

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for connections
    listen(server_socket, 5);
    printf("Server listening on port 8080...\n");

    // Accept client connections
    client_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);

    // Authentication
    char username[100];
    char password[100];
    recv(client_socket, username, sizeof(username), 0);
    recv(client_socket, password, sizeof(password), 0);

    if (authenticate(username, password, 1) == 1) {
        send(client_socket, "Authentication successful", 30, 0);
        printf(adminMenu);
	    send(client_socket, adminMenu, sizeof(adminMenu), 0);
        int choice;
        while(1)
        {
            recv(client_socket, &choice, sizeof(int), 0);
            switch(choice)
            {
                case 1:
                    send(client_socket, "Added Student", 13, 0);
                    break;
                case 2:
                    send(client_socket, "Viewed Student", 14, 0);
                    break;
                case 3:
                    send(client_socket, "Added Faculty", 13, 0);
                    break;
                case 4:
                    send(client_socket, "Viewed Faculty", 13, 0);
                    break;
                case 5:
                    send(client_socket, "Activated Student", 13, 0);
                    break;
                case 6:
                    send(client_socket, "Deactivated Student", 13, 0);
                    break;
                case 7:
                    send(client_socket, "Modified Student", 13, 0);
                    break;
                case 8:
                    send(client_socket, "Modified Faculty", 13, 0);
                    break;
                case 9:
                    send(client_socket, "Logged Out", 13, 0);
                    break;
            }
            if(choice == 9)
                break;
        }

    } else {
        send(client_socket, "Authentication failed", 21, 0);
    }

    // Cleanup
    close(client_socket);
    close(server_socket);

    return 0;
}

