#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "database.h"

void connect_to_host() {
    printf("Connecting to host %s with user %s and key %s...\n", db.hosts[0], db.users[0], db.keys[0]);
    char command[512];
    snprintf(command, sizeof(command), "ssh -i %s/%s %s@%s", db.key_path, db.keys[0], db.users[0], db.hosts[0]);
    system(command);
}

void add_host() {
    printf("Enter host address: ");
    scanf("%s", db.hosts[1]);
    printf("Enter host name: ");
    scanf("%s", db.last_connected_host);
    save_db();
}

void add_user() {
    printf("Enter user: ");
    scanf("%s", db.users[1]);
    save_db();
}

void add_key() {
    printf("Enter key: ");
    scanf("%s", db.keys[1]);
    save_db();
}

void advanced_submenu() {
    while (1) {
        printf(">>> Advanced:\n");
        printf("1. Remove Host\n2. Remove User\n3. Remove Key\n4. Nuke DB\n5. Back to Main Menu\n");
        printf("Choose option: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Host removed.\n");
                break;
            case 2:
                printf("User removed.\n");
                break;
            case 3:
                printf("Key removed.\n");
                break;
            case 4:
                printf("Database nuked.\n");
                break;
            case 5:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
